

import cv2
import numpy as np
import matplotlib.pyplot as plt
import sift_match as S
from PIL import Image
from osgeo import gdal
from scipy.spatial.distance import cdist
from scipy.ndimage import map_coordinates


def open(File):
    tifFile = File
    dataset = gdal.Open(tifFile)

    width = dataset.RasterXSize  # 栅格矩阵的列数
    height = dataset.RasterYSize  # 栅格矩阵的行数
    bands = dataset.RasterCount  # 波段数
    data = dataset.ReadAsArray(0, 0, width, height)  # 获取数据
    blueBand = data[0, 0:height, 0:width]  # 获取蓝波段
    greenBand = data[1, 0:height, 0:width]  # 获取绿波段
    redBand = data[2, 0:height, 0:width]  # 获取红波段

    if blueBand.dtype == np.uint16:
        # 计算每个波段的最大最小值
        min_value_blue = np.min(blueBand)
        max_value_blue = np.max(blueBand)
        min_value_green = np.min(greenBand)
        max_value_green = np.max(greenBand)
        min_value_red = np.min(redBand)
        max_value_red = np.max(redBand)

        # 最大最小值拉伸
        blueBand = np.clip((blueBand - min_value_blue) * (255 / (max_value_blue - min_value_blue)), 0, 255).astype(
            np.uint8)
        greenBand = np.clip((greenBand - min_value_green) * (255 / (max_value_green - min_value_green)), 0, 255).astype(
            np.uint8)
        redBand = np.clip((redBand - min_value_red) * (255 / (max_value_red - min_value_red)), 0, 255).astype(np.uint8)

    rgb_image = np.zeros((redBand.shape[0], redBand.shape[1], 3), dtype=np.uint8)
    rgb_image[:, :, 0] = redBand
    rgb_image[:, :, 1] = greenBand
    rgb_image[:, :, 2] = blueBand

    return rgb_image

# 直方图计算
def calculate_histogram(im_image):
    hist = np.zeros(256)
    for row in im_image:
        for pixel_value in row:
            hist[int(pixel_value)] += 1
    return hist


# 直方图均衡化
def hist_equalized(image):
    equalized_image = np.zeros(image.shape, dtype=np.uint8)
    cumulative_histograms = []
    for i in range(3):
        channel = image[:, :, i]
        histogram = calculate_histogram(channel)
        cumulative_histogram = np.cumsum(histogram)
        normalized_cumulative_histogram = cumulative_histogram / np.sum(histogram)
        equalized_channel = np.interp(channel, range(256), normalized_cumulative_histogram * 255)
        equalized_image[:, :, i] = equalized_channel
        cumulative_histograms.append(normalized_cumulative_histogram)
    return equalized_image, cumulative_histograms


# 尺寸调整
def adjust_size(image1, image2):
    img1 = image1.copy()
    img2 = image2.copy()

    # 获取图像1和图像2的最大宽度和最大高度
    max_width = max(img1.shape[1], img2.shape[1])
    max_height = max(img1.shape[0], img2.shape[0])

    # 调整图像1的尺寸
    img1 = cv2.resize(img1, (max_width, max_height))

    # 调整图像2的尺寸
    img2 = cv2.resize(img2, (max_width, max_height))

    return img1, img2

# 图像色彩匹配
def hist_matching(image1, image2):
    target_image = image1.copy()  # 待匹配图像
    refer_image = image2.copy()  # 参考影像

    # 创建输出图像
    output_image = np.zeros_like(refer_image)

    # 计算原始图像的累积直方图
    equalized_image, cumulative_hist = hist_equalized(target_image)

    # 计算参考图像的累积直方图
    target_equalized_image, target_cumulative_hist = hist_equalized(refer_image)

    for channel in range(3):
        # 对于原始图像中的每个像素
        pixel_values = target_image[:, :, channel].ravel()
        diffs = cdist(target_cumulative_hist[channel][:, None], cumulative_hist[channel][pixel_values][:, None],
                      metric='euclidean')
        closest_values = np.argmin(diffs, axis=0)
        output_image[:, :, channel] = closest_values.reshape(target_image.shape[0], target_image.shape[1])

        # for i in range(target_image.shape[0]):
        #     for j in range(target_image.shape[1]):
        #         pixel_value = target_image[i, j, channel]
        #         min_diff = float('inf')
        #         closest_value = None
        #         for k in range(len(target_cumulative_hist[channel])):
        #             diff = abs(target_cumulative_hist[channel][k] - cumulative_hist[channel][pixel_value])
        #             if diff < min_diff:
        #                 min_diff = diff
        #                 closest_value = k
        #
        #         output_image[i, j, channel] = closest_value

    plt.subplot(1, 3, 1)
    plt.imshow(image1)
    plt.axis('off')
    plt.title('Original Image')

    plt.subplot(1, 3, 2)
    plt.imshow(refer_image)
    plt.axis('off')
    plt.title('Target Image')

    plt.subplot(1, 3, 3)
    plt.imshow(output_image)
    plt.axis('off')
    plt.title('Matched Image')

    plt.tight_layout()
    plt.show()

    return output_image, refer_image

# 预处理
def process(path1, path2):
    image1 = open(path1)
    image2 = open(path2)
    img1 = image1.copy()
    img2 = image2.copy()
    size1, size2 = adjust_size(img1, img2)

    origin1, origin2 = hist_matching(size1, size2)

    gray1 = origin1.mean(axis=-1)
    gray2 = origin2.mean(axis=-1)

    return origin1, origin2, gray1, gray2

def load_data(path1,path2):
    originimg1 = cv2.imread(path1)

    # 如果是彩色图，转成灰度图
    if len(originimg1.shape) == 3:
        img1 = originimg1.mean(axis=-1)
    else:
        img1 = originimg1

    originimg2 = cv2.imread(path2)
    if len(originimg2.shape) == 3:
        img2 = originimg2.mean(axis=-1)
    else:
        img2 = originimg2

    ScaleRatio = img1.shape[0] * 1.0 / img2.shape[0]

    img2 = np.array(
        Image.fromarray(img2).resize((int(round(ScaleRatio * img2.shape[1])), img1.shape[0]), Image.BICUBIC))
    return originimg1,originimg2,img1,img2


def Lines(img, info, color=(0, 0, 255), err=700):
    if len(img.shape) == 2:
        result = np.dstack((img, img, img))
    else:
        result = img
    k = 0
    for i in range(result.shape[0]):
        for j in range(result.shape[1]):
            temp = (info[:, 1] - info[:, 0])
            A = (j - info[:, 0]) * (info[:, 3] - info[:, 2])
            B = (i - info[:, 2]) * (info[:, 1] - info[:, 0])
            temp[temp == 0] = 1e-9
            t = (j - info[:, 0]) / temp
            e = np.abs(A - B)
            temp = e < err
            if (temp * (t >= 0) * (t <= 1)).any():
                result[i, j] = color
                k += 0.1
    return result


def drawLines(X1, X2, Y1, Y2, dis, img, num=10):
    info = list(np.dstack((X1, X2, Y1, Y2, dis))[0])
    info = sorted(info, key=lambda x: x[-1])
    info = np.array(info)
    info = info[:min(num, info.shape[0]), :]
    img = Lines(img, info)
    # plt.imsave('./sift/3.jpg', img)

    if len(img.shape) == 2:
        plt.imshow(img.astype(np.uint8), cmap='gray')
    else:
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        plt.imshow(img.astype(np.uint8))
    plt.axis('off')
    # plt.plot([info[:,0], info[:,1]], [info[:,2], info[:,3]], 'c')
    # fig = plt.gcf()
    # fig.set_size_inches(int(img.shape[0]/100.0),int(img.shape[1]/100.0))
    plt.savefig('result.jpg')
    plt.show()


def get_homo(originimg1,originimg2,img1,img2):
    k1, d1 = S.SIFT(img1)
    k2, d2 = S.SIFT(img2)

    indexs = []
    deltas = []
    for i in range(len(k2)):
        ds = d2[i]
        mindetal = 10000000
        index = -1
        detal = 0
        for j in range(len(k1)):
            ds0 = d1[j]
            d = np.array(ds) - np.array(ds0)  # 计算差异
            detal = d.dot(d)
            if (detal <= mindetal):
                mindetal = detal
                index = j
        indexs.append(index)
        deltas.append(mindetal)

    k1 = np.array(k1)[:, :2]
    k2 = np.array(k2)[:, :2]

    #k2[:, 1] = img1.shape[1] + k2[:, 1]

    #origimg2 = np.array(Image.fromarray(originimg2).resize((img2.shape[1], img2.shape[0]), Image.BICUBIC))
    #result = np.hstack((originimg1, origimg2))

    k1 = k1[indexs[:]]

    X1 = k1[:, 1]
    X2 = k2[:, 1]
    Y1 = k1[:, 0]
    Y2 = k2[:, 0]
    #drawLines(X1, X2+img1.shape[1], Y1, Y2, deltas, result)

    #k1 = np.float32(k1)
    #k2 = np.float32(k2)
    k1_points = np.column_stack((X1, Y1))
    k2_points = np.column_stack((X2, Y2))
    k1_points=np.float32(k1_points).reshape(-1,1,2)
    k2_points=np.float32(k2_points).reshape(-1,1,2)
    #print("k1_points:",k1_points)
    #print("k2_points:",k2_points)

    H, _ = cv2.findHomography(k1_points, k2_points, cv2.RANSAC, 5.0)
    #print(H)
    return H


def perspectiveTransform(points, H):
    # Ensure points is a 3D array
    if len(points.shape) == 2:
        points = points.reshape(-1, 1, 2)

    # Add a column of ones to make the points homogeneous
    homogeneous_points = np.concatenate([points, np.ones((points.shape[0], 1, 1))], axis=-1)

    # Apply perspective transformation
    transformed_points = np.matmul(H, homogeneous_points.transpose(0, 2, 1))

    # Convert back to Cartesian coordinates
    transformed_points = transformed_points.transpose(0, 2, 1) / transformed_points[:, 2, :].reshape(-1, 1, 1)
    return transformed_points[:, :, :2]


def warpPerspective(img, H, output_size):
    # Get the height and width of the output image
    out_width, out_height = output_size

    # Generate the grid of coordinates for the output image
    grid_x, grid_y = np.meshgrid(np.arange(out_width), np.arange(out_height))
    grid_coords = np.vstack((grid_x.flatten(), grid_y.flatten(), np.ones_like(grid_x.flatten())))

    # Apply the inverse transformation to find corresponding coordinates in the input image
    inv_H = np.linalg.inv(H)
    input_coords = np.dot(inv_H, grid_coords)

    # Normalize coordinates
    input_coords = input_coords[:2, :] / input_coords[2, :]
    input_coords = input_coords.reshape(2, out_height, out_width).transpose(1, 2, 0)
    input_coords = input_coords.astype(np.float32)
    # Use OpenCV's remap function to perform the actual image transformation
    warped_img = cv2.remap(img, input_coords, None, interpolation=cv2.INTER_LINEAR)
    return warped_img


def stitch_image(img1, img2, H):
    h1, w1 = img1.shape[:2]
    h2, w2 = img2.shape[:2]

    img1_dims = np.float32([[0, 0], [0, h1], [w1, h1], [w1, 0]]).reshape(-1, 1, 2)
    img2_dims = np.float32([[0, 0], [0, h2], [w2, h2], [w2, 0]]).reshape(-1, 1, 2)
    ########1111
    img1_transform = perspectiveTransform(img1_dims, H)  #####

    result_dims = np.concatenate((img2_dims, img1_transform), axis=0)  ######
    [x_min, y_min] = np.int32(result_dims.min(axis=0).ravel() - 0.5)
    [x_max, y_max] = np.int32(result_dims.max(axis=0).ravel() + 0.5)

    transform_dist = [-x_min, -y_min]
    transform_array = np.array([[1, 0, transform_dist[0]],
                                [0, 1, transform_dist[1]],
                                [0, 0, 1]])
    result_img = warpPerspective(img1, transform_array.dot(H), (x_max - x_min, y_max - y_min))  ######

    result_img[transform_dist[1]:transform_dist[1] + h2,
    transform_dist[0]:transform_dist[0] + w2] = img2
    return result_img

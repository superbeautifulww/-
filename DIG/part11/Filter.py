import numpy as np
import math
import cv2
import image_enhancement as I
'''
def convolve(img, kernel):
    image_h, image_w = img.shape
    kernel_h, kernel_w = kernel.shape

    # 计算填充的大小
    pad_h = kernel_h // 2
    pad_w = kernel_w // 2

    pad_image = np.pad(img, ((pad_h, pad_h), (pad_w, pad_w)), mode='reflect')
    conv_image = np.zeros_like(img, dtype=np.float32)

    for i in range(pad_h, image_h + pad_h):
        for j in range(pad_w, image_w + pad_w):
            region = pad_image[i - pad_h: i + pad_h + 1, j - pad_w: j + pad_w + 1]
            conv_image[i - pad_h, j - pad_w] = np.sum(region * kernel)
    print("conv1",conv_image)
    conv_image = np.clip(conv_image, 0, 255)
    return conv_image
'''



def convolve(img, kernel):
    img = img.astype(np.float32)
    kernel = kernel.astype(np.float32)

    image_h, image_w = img.shape
    kernel_h, kernel_w = kernel.shape

    # 计算填充的大小
    pad_h = kernel_h // 2
    pad_w = kernel_w // 2

    pad_image = np.pad(img, ((pad_h, pad_h), (pad_w, pad_w)), mode='reflect')

    # 利用numpy的卷积操作
    conv_image = np.zeros_like(img)
    for i in range(image_h):
        for j in range(image_w):
            region = pad_image[i:i + kernel_h, j:j + kernel_w]
            conv_image[i, j] = np.sum(region * kernel)

    # 使用clip函数确保结果在0到255的范围内
    conv_image = np.clip(conv_image, 0, 255)

    return conv_image


def gaussian_filter(img,kernel_size,sigma):
    kernel_height,kernel_width=kernel_size
    height,width,channels=img.shape
    resimg=img.copy()
    pad_num = int(kernel_width / 2)

    pad_img = np.pad(img, ((pad_num, pad_num), (pad_num, pad_num), (0, 0)), 'constant')

    # 生成高斯核
    r, c = np.mgrid[0:kernel_height, 0:kernel_width]
    r -= (kernel_height - 1) // 2
    c -= (kernel_width - 1) // 2
    r = r.astype(int)
    c = c.astype(int)
    kernel = np.exp(-(r ** 2 + c ** 2) / (2.0 * sigma ** 2))
    kernel /= kernel.sum()
    print(kernel)

    for i in range(height):
        for j in range(width):
            for c in range(channels):
                resimg[i, j, c] = np.uint8(np.sum(kernel * pad_img[i:i+kernel_height, j:j+kernel_width, c]))

    return resimg
def median_filter(img,kernel_size):
    kernel_height, kernel_width = kernel_size
    height, width, channels = img.shape
    pad_num = int(kernel_height / 2) # 计算需要添加的边
    median = int(np.round((kernel_height * kernel_width) / 2))  # 计算中位数

    pad_img = np.pad(img, ((pad_num, pad_num), (pad_num, pad_num), (0, 0)), 'constant')
    resimg = img.copy()

    for c in range(channels):
        for i in range(pad_num, height):  # 滤波
            for j in range(pad_num, width):

                temp = pad_img[i - pad_num:i + pad_num + 1,j - pad_num:j + pad_num + 1, c].flatten().tolist()  # 获取n*n的矩阵并平展
                temp = sorted(temp)  # 排序
                resimg[i - pad_num, j - pad_num, c] = temp[median]  # 更新像素值

    resimg = resimg.astype(np.uint8)
    return resimg
def mean_filter(img,kernel_size):
    kernel_height, kernel_width = kernel_size
    height, width, channels = img.shape
    resimg = img.copy()
    pad_num = int(np.floor(kernel_width / 2))  # 计算需要加的边

    pad_img = np.pad(img, ((pad_num, pad_num), (pad_num, pad_num), (0, 0)), 'constant')

    for c in range(channels):
        for i in range(pad_num, height):  # 滤波
            for j in range(pad_num, width):
                mean_value = np.mean(pad_img[i - pad_num:i + pad_num + 1, j - pad_num:j + pad_num + 1, c])
                resimg[i - pad_num, j - pad_num, c] = mean_value  # 更新像素值

    return resimg
def motion_filter(img,kernel_size):
    kernel_height, kernel_width = kernel_size
    height, width, channels = img.shape
    resimg = img.copy()
    pad_num = int(kernel_width / 2)  # 计算需要加的边
    pad_img = np.pad(img, ((pad_num, pad_num), (pad_num, pad_num), (0, 0)), 'constant')

    motion_kernel = np.zeros(kernel_size)
    for i in range(kernel_width):
        motion_kernel[i][i] = 1.0 / kernel_width

    for c in range(channels):
            for i in range(pad_num,height):
                for j in range(pad_num,width):
                    temp = np.sum(pad_img[i - pad_num:i + pad_num + 1, j - pad_num:j + pad_num + 1, c] * motion_kernel)
                    resimg[i - pad_num, j - pad_num, c] = temp
    return resimg
def max_min_filter(img,kernel_size):
    kernel_height, kernel_width = kernel_size
    height, width = img.shape
    resimg = np.zeros((height, width), dtype=np.uint8)

    pad_num = kernel_width // 2
    pad_img = np.pad(img, ((pad_num, pad_num), (pad_num, pad_num)), 'constant')

    for i in range(height):
        for j in range(width):
            temp = pad_img[i:i + kernel_height, j:j + kernel_width]
            resimg[i, j] = np.max(temp) - np.min(temp)

    return resimg
def different_filter(img,type):
    if type == 'vertical':
        kernel = np.array([[0, -1, 0],
                           [0, 1, 0],
                           [0, 0, 0]],dtype=np.float32)
    else:
        kernel = np.array([[0, 0, 0],
                           [-1, 1, 0],
                           [0, 0, 0]],dtype=np.float32)
    img = img.astype(np.float32)
    resimg=cv2.filter2D(img,-1,kernel)
    return resimg

def sobel_filter(img,type):
    kernel = np.array([[1, 2, 1], [0, 0, 0], [-1, -2, -1]]).astype(np.int32)
    if type=='horizontal':  kernel=kernel.T
    resimg = convolve(img, kernel)
    return resimg

def prewitt_filter(img,type):
    kernel = np.array([[-1, 0, 1],
                      [-1, 0, 1],
                      [-1, 0, 1]])
    if type=='vertical':  kernel=kernel.T
    resimg = cv2.filter2D(img,-1,kernel)
    return resimg

def laplacian_filter(img):
    laplacian_kernel = np.array([[0, 1, 0],
                                 [1, -4, 1],
                                 [0, 1, 0]], dtype=np.float32)

    img_float = img.astype(np.float32)
    resimg = cv2.filter2D(img_float, -1, laplacian_kernel)
    return resimg


def emboss_filter(img):
    emboss_kernel=np.array([[-2,-1,0],
                               [-1,1,1],
                               [0,1,2]])
    resimg = convolve(img, emboss_kernel)
    return resimg



def LoG_filter(img,kernel_size,sigma):
    kernel_height, kernel_width = kernel_size
    height, width = img.shape
    resimg = np.zeros((height, width), dtype=np.float32)

    pad_num = int(kernel_width / 2)  # 计算需要加的边
    pad_img = np.pad(img, pad_width=pad_num, mode='constant')

    kernel=np.zeros(kernel_size)
    center = kernel_height // 2
    for i in range(kernel_height):
        for j in range(kernel_width):
            x = i - center
            y = j - center
            kernel[i, j] = (x ** 2 + y ** 2 - 2 * sigma ** 2) / (2 * np.pi * sigma ** 6) * np.exp(
                -(x ** 2 + y ** 2) / (2 * sigma ** 2))
    kernel = kernel - np.mean(kernel)
    pad_img[pad_num:pad_num + height, pad_num:pad_num + width] = img
    pad_img=pad_img.astype(np.float32)

    for i in range(height):
        for j in range(width):
            temp = np.sum(pad_img[i:i + kernel_height, j:j + kernel_width] * kernel)
            resimg[i, j] = temp

    return resimg.astype(np.float32)



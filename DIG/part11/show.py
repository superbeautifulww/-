import image_enhancement as I
import numpy as np
import matplotlib.pyplot as plt
import Filter as F
import cv2
import EdgeDetection as E

def loaddata(img,index,l=0,r=255):
    show_img=img[index,:,:].astype(np.float64)

    rp=I.cut_linear_stretching(show_img[0],l,r)
    gp=I.cut_linear_stretching(show_img[1],l,r)
    bp=I.cut_linear_stretching(show_img[2],l,r)

    show_img = np.stack((bp, gp, rp), axis=-1)
    return show_img

def histogram_normalization_visual(img,l=0,r=255):
    resimg = I.histogram_normalization(img,l,r)
    standard_img=cv2.normalize(img, None, alpha=l, beta=r, norm_type=cv2.NORM_MINMAX, dtype=cv2.CV_8U)

    plt.figure(figsize=(10,10))

    plt.subplot(2, 3, 1)
    plt.imshow(img.astype(np.uint8))
    plt.title('Image')

    plt.subplot(2, 3, 2)
    plt.imshow(resimg.astype(np.uint8))
    plt.title('Image result')

    plt.subplot(2, 3, 4)
    plt.hist(img.ravel(), bins=50, range=(0, 255), density=False, color='gray', alpha=0.7)
    plt.title('Histogram')

    plt.subplot(2, 3, 5)
    plt.hist(resimg.ravel(), bins=50, range=(0, 255), density=False, color='gray', alpha=0.7)
    plt.title('Histogram result')

    plt.subplot(2, 3, 3)
    plt.imshow(standard_img.astype(np.uint8))
    plt.title('Standard result')

    plt.subplot(2, 3, 6)
    plt.hist(standard_img.ravel(), bins=50, range=(0, 255), density=False, color='gray', alpha=0.7)
    plt.title('Standard Histogram result')

    plt.suptitle('Histogram Normalization Visualization')
    # 显示图像
    plt.show()

def histogram_equalization_visual(img,z_max=255):
    resimg = I.histogram_equalization(img,z_max)
    img = img.astype(np.uint8)
    '''
    standard_img = cv2.cvtColor(img, cv2.COLOR_BGR2YUV)  # 转换为YUV色彩空间
    standard_img[:, :, 0] = cv2.equalizeHist(standard_img[:, :, 0])  # 对Y通道进行直方图均衡化
    standard_img = cv2.cvtColor(standard_img, cv2.COLOR_YUV2BGR)  # 转回BGR色彩空间
    '''
    standard_img = np.zeros_like(img)
    for channel in range(img.shape[2]):
        standard_img[:, :, channel] = cv2.equalizeHist(img[:, :, channel])

    plt.figure(figsize=(10, 10))

    plt.subplot(2, 3, 1)
    plt.imshow(img.astype(np.uint8))
    plt.title('Image')

    plt.subplot(2, 3, 2)
    plt.imshow(resimg.astype(np.uint8))
    plt.title('Image result')

    plt.subplot(2, 3, 4)
    plt.hist(img.ravel(), bins=50, range=(0, 255), density=False, color='gray', alpha=0.7)
    plt.title('Histogram')

    plt.subplot(2, 3, 5)
    plt.hist(resimg.ravel(), bins=50, range=(0, 255), density=False, color='gray', alpha=0.7)
    plt.title('Histogram result')

    plt.subplot(2, 3, 3)
    plt.imshow(standard_img.astype(np.uint8))
    plt.title('Standard result')

    plt.subplot(2, 3, 6)
    plt.hist(standard_img.ravel(), bins=50, range=(0, 255), density=False, color='gray', alpha=0.7)
    plt.title('Standard Histogram result')

    plt.suptitle('Histogram Equalization Visualization')
    # 显示图像
    plt.show()

def histogram_matching_visual(img,reference):
    resimg = I.histogram_matching(img,reference)
    plt.figure(figsize=(10,10))

    plt.subplot(2, 3, 1)
    plt.imshow(img.astype(np.uint8))
    plt.title('Image')

    plt.subplot(2, 3, 2)
    plt.imshow(resimg.astype(np.uint8))
    plt.title('Image result')

    plt.subplot(2, 3, 3)
    plt.imshow(reference.astype(np.uint8))
    plt.title('Image referrence')

    plt.subplot(2, 3, 4)
    plt.hist(img.ravel(), bins=50, range=(0, 255), density=False, color='gray', alpha=0.7)
    plt.title('Histogram')

    plt.subplot(2, 3, 5)
    plt.hist(resimg.ravel(), bins=50, range=(0, 255), density=False, color='gray', alpha=0.7)
    plt.title('Histogram result')

    plt.subplot(2, 3, 6)
    plt.hist(reference.ravel(), bins=50, range=(0, 255), density=False, color='gray', alpha=0.7)
    plt.title('Histogram result')

    plt.suptitle('Histogram Matching Visualization')
    # 显示图像
    plt.show()

def linear_stretching_visual(img,l=0,r=255):
    resimg = I.linear_stretching(img, l, r)
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 2, 1)
    plt.imshow(img.astype(np.uint8))
    plt.title('Image')

    plt.subplot(1, 2, 2)
    plt.imshow(resimg.astype(np.uint8))
    plt.title('Image result')

    plt.suptitle('Linear stretching Visualization')
    # 显示图像
    plt.show()

def cut_linear_stretching_visual(img,l=0,r=255):
    resimg = I.cut_linear_stretching(img, l, r)
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 2, 1)
    plt.imshow(img.astype(np.uint8))
    plt.title('Image')

    plt.subplot(1, 2, 2)
    plt.imshow(resimg.astype(np.uint8))
    plt.title('Image result')

    plt.suptitle('Cut Linear stretching Visualization')
    # 显示图像
    plt.show()

def thresholding_visual(img,th=128):
    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)
    resimg = I.thresholding(img, th)

    _, standard_img = cv2.threshold(img, th, 255, cv2.THRESH_BINARY)

    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8),cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg.astype(np.uint8),cmap='gray')
    plt.title('Image result')

    plt.subplot(1, 3, 3)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Standard result')

    plt.suptitle('Thresholding Visualization')
    # 显示图像
    plt.show()

def otsu_binarization_visual(img,th=128):
    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)
    resimg = I.otsu_binarization(img)
    _, standard_img = cv2.threshold(img, th, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8), cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg.astype(np.uint8), cmap='gray')
    plt.title('Image result')

    plt.subplot(1, 3, 3)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Standard result')

    plt.suptitle('Otsu Binarization Visualization')
    # 显示图像
    plt.show()

def average_pooling_visual(img,size=8):
    resimg = I.average_pooling(img,size)
    standard_img=cv2.blur(img, (size,size))
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8),cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg.astype(np.uint8),cmap='gray')
    plt.title('Image result')

    plt.subplot(1, 3, 3)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Standard result')

    plt.suptitle('Average pooling Visualization')
    # 显示图像
    plt.show()

def max_pooling_visual(img,size=8):
    resimg = I.max_pooling(img,size)
    standard_img = cv2.dilate(img, (size, size))
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8), cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg.astype(np.uint8), cmap='gray')
    plt.title('Image result')

    plt.subplot(1, 3, 3)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Standard result')

    plt.suptitle('Max pooling Visualization')
    # 显示图像
    plt.show()

def gaussian_filter_visual(img,kernel_size=(3,3),sigma=1.3):
    resimg = F.gaussian_filter(img,kernel_size,sigma)
    standard_img=cv2.GaussianBlur(img, kernel_size, sigma, sigma)
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8), cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg.astype(np.uint8), cmap='gray')
    plt.title('Image result')

    plt.subplot(1, 3, 3)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Standard result')

    plt.suptitle('Gaussian filter Visualization')
    # 显示图像
    plt.show()

def median_filter_visual(img,kernel_size=(3,3)):
    resimg = F.median_filter(img,kernel_size)

    img = img.astype(np.uint8)
    standard_img=cv2.medianBlur(img, ksize=3)

    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8), cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg.astype(np.uint8), cmap='gray')
    plt.title('Image result')

    plt.subplot(1, 3, 3)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Standard result')

    plt.suptitle('Median filter Visualization')
    # 显示图像
    plt.show()

def mean_filter_visual(img,kernel_size=(3,3)):
    resimg = F.mean_filter(img,kernel_size)
    standard_img=cv2.blur(img, kernel_size)
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8), cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg.astype(np.uint8), cmap='gray')
    plt.title('Image result')

    plt.subplot(1, 3, 3)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Standard result')

    plt.suptitle('Mean filter Visualization')
    # 显示图像
    plt.show()

def motion_filter_visual(img,kernel_size=(3,3)):
    resimg = F.motion_filter(img,kernel_size)
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 2, 1)
    plt.imshow(img.astype(np.uint8))
    plt.title('Image')

    plt.subplot(1, 2, 2)
    plt.imshow(resimg.astype(np.uint8))
    plt.title('Image result')

    plt.suptitle('Motion filter Visualization')
    # 显示图像
    plt.show()

def max_min_filter_visual(img,kernel_size=(3,3)):
    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)
    max_filtered = cv2.dilate(img, np.ones(kernel_size, np.uint8))
    min_filtered = cv2.erode(img, np.ones(kernel_size, np.uint8))
    standard_img = cv2.subtract(max_filtered, min_filtered)
    resimg = F.max_min_filter(img,kernel_size)
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8),cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg.astype(np.uint8),cmap='gray')
    plt.title('Image result')

    plt.subplot(1, 3, 3)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Standard result')

    plt.suptitle('Max-Min filter Visualization')
    # 显示图像
    plt.show()

def different_filter_visual(img):
    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)
    resimg1 = F.different_filter(img,'vertical')
    resimg2=F.different_filter(img,'horizontal')


    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8),cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg1.astype(np.uint8),cmap='gray',vmin=0,vmax=128)
    plt.title('Vertical Filter result')

    plt.subplot(1, 3, 3)
    plt.imshow(resimg2.astype(np.uint8), cmap='gray',vmin=0,vmax=128)
    plt.title('Horizontal Filter result')

    plt.suptitle('Different filter Visualization')
    # 显示图像
    plt.show()

def sobel_filter_visual(img):
    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)
    resimg1 = F.sobel_filter(img, 'vertical')
    resimg2 = F.sobel_filter(img, 'horizontal')
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8), cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg1.astype(np.uint8), cmap='gray')
    plt.title('Vertical Filter result')

    plt.subplot(1, 3, 3)
    plt.imshow(resimg2.astype(np.uint8), cmap='gray')
    plt.title('Horizontal Filter result')

    plt.suptitle('Sobel filter Visualization')
    # 显示图像
    plt.show()

def prewitt_filter_visual(img):
    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)
    resimg1 = F.prewitt_filter(img, 'vertical')
    resimg2 = F.prewitt_filter(img, 'horizontal')
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8), cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg1.astype(np.uint8), cmap='gray')
    plt.title('Vertical Filter result')

    plt.subplot(1, 3, 3)
    plt.imshow(resimg2.astype(np.uint8), cmap='gray')
    plt.title('Horizontal Filter result')

    plt.suptitle('Prewitt filter Visualization')
    # 显示图像
    plt.show()

def laplacian_filter_visual(img):
    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)
    resimg = F.laplacian_filter(img)
    standard_img = cv2.Laplacian(img, cv2.CV_64F)
    plt.figure(figsize=(10, 10))



    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8),cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(resimg.astype(np.uint8),cmap='gray')
    plt.title('Image result')

    plt.subplot(1, 3, 3)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Standard result')

    plt.suptitle('Laplacian filter Visualization')
    # 显示图像
    plt.show()

def emboss_filter_visual(img):
    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)

    resimg = F.emboss_filter(img)
    plt.figure(figsize=(10, 10))

    plt.subplot(1, 2, 1)
    plt.imshow(img.astype(np.uint8),cmap='gray')
    plt.title('Image')

    plt.subplot(1, 2, 2)
    plt.imshow(resimg.astype(np.uint8),cmap='gray')
    plt.title('Image result')

    plt.suptitle('Emboss filter Visualization')
    # 显示图像
    plt.show()

def LOG_filter_visual(img,kernel_size=(3,3),sigma=1.3):
    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)
    resimg = F.LoG_filter(img, kernel_size, sigma)


    plt.figure(figsize=(10, 10))

    plt.subplot(1, 2, 1)
    plt.imshow(img.astype(np.uint8),cmap='gray')
    plt.title('Image')


    plt.subplot(1, 2, 2)
    plt.imshow(resimg.astype(np.uint8),cmap='gray')
    plt.title('Image result')

    plt.suptitle('LoG filter Visualization')
    # 显示图像
    plt.show()

def Canny_EdgeDetection_visual(img):
    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)
    resimg=E.Canny_EdgeDetection(img,(5,5),1.4,100,20)
    standard_img = cv2.Canny(img, threshold1=100, threshold2=20)

    plt.figure(figsize=(10, 10))

    plt.subplot(1, 3, 1)
    plt.imshow(img.astype(np.uint8), cmap='gray')
    plt.title('Image')

    plt.subplot(1, 3, 2)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Image result')

    plt.subplot(1, 3, 3)
    plt.imshow(standard_img.astype(np.uint8), cmap='gray')
    plt.title('Standard result')



    plt.suptitle('Canny EdgeDetection Visualization')
    # 显示图像
    plt.show()

def hough_transform_visual(img):
    show_picture=img.copy()
    #show_picture=cv2.cvtColor(show_picture.astype(np.uint8),cv2.COLOR_BGR2RGB)

    img = cv2.cvtColor(img.astype(np.uint8), cv2.COLOR_BGR2GRAY)
    img = E.Canny_EdgeDetection(img, (5,5),1.4,100, 30)
    res = E.hough_transform(img)

    resimg = np.copy(show_picture)
    for line in res:
        cv2.line(resimg, line[0], line[1], (255, 0, 0), 2)

    plt.figure(figsize=(10, 10))

    plt.subplot(1, 2, 1)
    plt.imshow(show_picture.astype(np.uint8))
    plt.title('Image')

    plt.subplot(1, 2, 2)
    plt.imshow(resimg.astype(np.uint8))
    plt.title('Image result')

    plt.suptitle('Hough Transform Visualization')
    # 显示图像
    plt.show()




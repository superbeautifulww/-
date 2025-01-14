import numpy as np
from osgeo import gdal



def histogram_normalization(img,a=0,b=255):
    c=img.min()
    d=img.max()
    resimg=img.copy()

    resimg=(b-a)/(d-c)*(resimg-c)+a
    resimg[resimg<a]=a
    resimg[resimg>b]=b
    resimg = resimg.astype(np.uint8)
    return resimg

def histogram_equalization(img,z_max=255):

    img = img.astype(np.uint8)

    resimg = np.zeros_like(img)
    for channel in range(img.shape[2]):
        # 计算每个通道的直方图
        hist, bins = np.histogram(img[:, :, channel], bins=256, range=(0, 256))

        # 计算累积分布函数
        cdf = hist.cumsum()
        cdf_masked = np.ma.masked_equal(cdf, 0)
        cdf_normalized = ((cdf_masked - cdf_masked.min()) * z_max / (cdf_masked.max() - cdf_masked.min())).filled(0).astype('uint8')

        # 对原始图像进行映射
        resimg[:, :, channel] = cdf_normalized[img[:, :, channel]]

    return resimg

def histogram_matching(img,reference):
    resimg = img.copy()
    hist_img, _ = np.histogram(img, bins=256, range=(0, 256), density=True)
    hist_reference, _ = np.histogram(reference, bins=256, range=(0, 256), density=True)
    #计算累积分布函数
    cdf_img = np.cumsum(hist_img)
    cdf_reference = np.cumsum(hist_reference)
    # 对每个像素的值进行直方图匹配
    for i in range(256):
        closest_value = np.argmin(np.abs(cdf_img[i] - cdf_reference))
        resimg[img == i] = closest_value
    return resimg

def linear_stretching(img,l=0,r=255):
    resimg=img.copy()
    maxval=resimg.max()
    minval=resimg.min()

    resimg=(resimg-minval)/(maxval-minval)
    resimg*=(r-l)
    return resimg

def cut_linear_stretching(img,l=0,r=255):
    resimg=img.copy()
    p2=np.percentile(img,2)
    p98=np.percentile(img,98)

    resimg=(resimg-p2)/(p98-p2)
    resimg*=(r-l)
    resimg[resimg<l]=l
    resimg[resimg>r]=r
    return resimg

def thresholding(img,th=128):

    resimg=img.copy()
    resimg[resimg < th] = 0
    resimg[resimg > th] = 255
    return resimg

def otsu_binarization(img):

    resimg=img.copy()
    height=img.shape[0]
    width=img.shape[1]
    max_sigma=0
    max_t=0
    for i in range(255):
        n0=img[np.where(img<i)]
        n1=img[np.where(img>=i)]
        w0=len(n0)/(height*width)
        w1 = len(n1) / (height * width)
        u0=0
        if len(n0)>0:u0=np.mean(n0)
        u1=0
        if len(n1)>0:u1=np.mean(n1)

        sigma=w0*w1*(u0-u1)*(u0-u1)
        if sigma>max_sigma:
            max_sigma=sigma
            max_t=i
    resimg[resimg<max_t]=0
    resimg[resimg>=max_t]=255
    return resimg

def average_pooling(img,size=8):
    resimg = img.copy()
    height, width, channel = img.shape
    Nh = int(height / size)
    Nw = int(width / size)

    for c in range(channel):  # 对每个通道分别进行池化
        for y in range(Nh):
            for x in range(Nw):
                resimg[size * y:size * (y + 1), size * x:size * (x + 1), c] = np.mean(
                    resimg[size * y:size * (y + 1), size * x:size * (x + 1), c])
    return resimg


def max_pooling(img,size=8):
    resimg = img.copy()
    height, width, channel = img.shape
    Nh = int(height / size)
    Nw = int(width / size)

    for c in range(channel):  # 对每个通道分别进行池化
        for y in range(Nh):
            for x in range(Nw):
                resimg[size * y:size * (y + 1), size * x:size * (x + 1), c] = np.mean(
                    resimg[size * y:size * (y + 1), size * x:size * (x + 1), c])
    return resimg


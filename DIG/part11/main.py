import matplotlib.pyplot as plt
import numpy as np
import image_enhancement as I
from osgeo import gdal
import os
import cv2
import Filter as F
import EdgeDetection as E
import show
import matplotlib.cm as cm
from tkinter import *
from tkinter.filedialog import *
from PIL import Image, ImageTk


path="D:/pattern recognition/tiffjpg/qianjiang.tif"
dataset=gdal.Open(path)
img = dataset.ReadAsArray()
img=show.loaddata(img,index=np.array([2,1,0]),l=0,r=255)

#1.1.直方图归一化
#show.histogram_normalization_visual(img)

#img = dataset.ReadAsArray()
#img=S.loaddata(img, index=np.array([3,2,1]))

#1.2.直方图均衡化
#show.histogram_equalization_visual(img)

#1.3.直方图匹配

#reference = cv2.imread("D:/DIG/strawberry.jpg")
#reference = cv2.cvtColor(reference, cv2.COLOR_BGR2RGB)
#show.histogram_matching_visual(img,reference)

#img = dataset.ReadAsArray()
#img=show.loaddata(img,index=np.array([2,1,0]),l=40,r=200)

#1.4.线性拉伸
#show.linear_stretching_visual(img)

#1.5.2%线性拉伸
#show.cut_linear_stretching_visual(img)

#img = dataset.ReadAsArray()
#img=show.loaddata(img,index=np.array([2,1,0]))

#1.6.阈值二值化
#show.thresholding_visual(img)

#1.7.大津二值化
#show.otsu_binarization_visual(img)


#1.8.平均池化
#show.average_pooling_visual(img,15)

#1.9.最大池化
#show.max_pooling_visual(img,15)

#2.1.高斯滤波
#show.gaussian_filter_visual(img,(3,3),1.52)

#2.2.中值滤波
#show.median_filter_visual(img)

#2.3.均值滤波
#show.mean_filter_visual(img)

#2.4.运动滤波
#show.motion_filter_visual(img)


#img = cv2.imread("black2.png")
#img=cv2.imread("D:/DIG/strawberry.jpg")


#2.5.Max_min滤波
#show.max_min_filter_visual(img)

#2.6.Different滤波
#show.different_filter_visual(img)

#2.7.Sobel
#show.sobel_filter_visual(img)

#2.8.Prewitt
#show.prewitt_filter_visual(img)

#2.9.laplacian
#show.laplacian_filter_visual(img)

#2.10.Emboss
#show.emboss_filter_visual(img)

#2.11.log
#show.LOG_filter_visual(img)

#3.1Canny
#show.Canny_EdgeDetection_visual(img)



#3.2hough
show.hough_transform_visual(img)





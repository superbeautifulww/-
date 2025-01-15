# -*- coding: UTF-8 -*-
import numpy as np
import os
import sys
from PIL import Image
from osgeo import gdal, gdalconst

def readTif(original,bandsOrder=[3,2,1]):
    driver = gdal.GetDriverByName('GTiff')
    driver.Register()
    ds = gdal.Open(original, gdal.GA_ReadOnly)
    cols = ds.RasterXSize
    rows = ds.RasterYSize
    data=np.empty([rows,cols,3],dtype = float)
    for i in range(3):
        band=ds.GetRasterBand(bandsOrder[i])
        data1 = band.ReadAsArray()
        data[:,:,i]=data1
    return data

def stretchImg(imgPath, resultPath, lower_percent=0.6, higher_percent=99.4):
    data=readTif(imgPath)
    n = data.shape[2]
    out = np.zeros_like(data, dtype=np.uint8)
    for i in range(n):
        a = 0
        b = 255
        c = np.percentile(data[:, :,i], lower_percent)
        d = np.percentile(data[:, :,i], higher_percent)
        t = a + (data[:, :,i] - c) * (b - a) / (d - c)
        t[t < a] = a
        t[t > b] = b
        out[:, :,i] = t
    outImg=Image.fromarray(np.uint8(out))
    outImg.save(resultPath)


stretchImg('qianjiang.tif','qianjiang.jpg')
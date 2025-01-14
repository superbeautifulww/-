import math

import numpy as np
import cv2
import Filter as F

def gaussian_filter(img,kernel_size,sigma):
    kernel_height,kernel_width=kernel_size
    height,width=img.shape
    resimg=img.copy()
    pad_num = int(kernel_width / 2)

    pad_img = np.pad(img, ((pad_num, pad_num), (pad_num, pad_num)), 'constant')

    # 生成高斯核
    r, c = np.mgrid[0:kernel_height, 0:kernel_width]
    r -= (kernel_height - 1) // 2
    c -= (kernel_width - 1) // 2
    r = r.astype(int)
    c = c.astype(int)
    kernel = np.exp(-(r ** 2 + c ** 2) / (2.0 * sigma ** 2))
    kernel /= kernel.sum()

    for i in range(height):
        for j in range(width):
            resimg[i, j] = np.uint8(np.sum(kernel * pad_img[i:i+kernel_height, j:j+kernel_width]))

    return resimg

def Canny_EdgeDetection(img,kernel_size,sigma,high_threshold, low_threshold):
    img=img.copy()
    #1.高斯滤波（高斯模糊）
    img = gaussian_filter(img,kernel_size,sigma)
    #2.sobel滤波
    Ix=F.sobel_filter(img,'vertical')
    Iy=F.sobel_filter(img,'horizontal')
    #3.求出边缘梯度
    G = np.sqrt(Ix ** 2 + Iy ** 2)
    theta = np.arctan2(Iy, Ix) * (180 / np.pi)
    # 4.边缘细化
    M, N = G.shape
    result = np.zeros((M, N))
    for i in range(1, M - 1):
        for j in range(1, N - 1):
            angle = theta[i, j]
            value = G[i, j]
            q = value
            if (0 <= angle < np.pi / 8) or (15 * np.pi / 8 <= angle <= 2 * np.pi):
                r = G[i, j + 1]
                s = G[i, j - 1]
            elif (np.pi / 8 <= angle < 3 * np.pi / 8) or (9 * np.pi / 8 <= angle < 11 * np.pi / 8):
                r = G[i + 1, j - 1]
                s = G[i - 1, j + 1]
            elif (3 * np.pi / 8 <= angle < 5 * np.pi / 8) or (11 * np.pi / 8 <= angle < 13 * np.pi / 8):
                r = G[i + 1, j]
                s = G[i - 1, j]
            else:
                r = G[i - 1, j - 1]
                s = G[i + 1, j + 1]
            if (q >= r) and (q >= s):
                result[i, j] = q
            else:
                result[i, j] = 0

    #5.滞后阈值
    resimg = np.zeros((M, N), dtype=np.uint8)
    # 根据高阈值和低阈值进行边缘连接
    for i in range(1, M - 1):
        for j in range(1, N - 1):
            if result[i, j] >= high_threshold:
                resimg[i, j] = 255
            elif result[i, j] < low_threshold:
                resimg[i, j] = 0
            else:
                # 检查8邻域内是否有比高阈值高的像素
                neighbor_region = result[i - 1:i + 2, j - 1:j + 2]
                if (neighbor_region > high_threshold).any():
                    resimg[i, j] = 255
                else:
                    resimg[i, j] = 0
    return resimg





def hough_transform(img):
    #求出对角线长rmax
    height,width=img.shape
    rmax=int(np.sqrt(height**2+width**2))
    theta=180
    #在边缘点执行霍夫变换，投票
    hough_space = np.zeros((rmax, theta))
    y_coords, x_coords = np.nonzero(img)
    t = np.arange(180)
    for x, y in zip(x_coords, y_coords):
        r = np.round(x * np.cos(np.deg2rad(t)) + y * np.sin(np.deg2rad(t))).astype(np.uint8)
        r = np.clip(r, 0, rmax - 1)
        hough_space[r, t] += 1
    #NMS
    hough_space_max = cv2.dilate(hough_space, np.ones((3, 3), np.uint8))
    hough_space = np.where(hough_space == hough_space_max, hough_space, 0)
    # 提取前十名直线
    lines = []
    for i in range(10):
        while True:
            max_vote = np.max(hough_space)
            if max_vote == 0:
                break
            r_idx, t_idx = np.unravel_index(np.argmax(hough_space), hough_space.shape)
            r = r_idx
            t = t_idx
            print(r,t)
            # 检查新的直线是否与已经提取出的直线过于接近
            too_close = False
            for r0, t0 in lines:
                if  abs(t - t0) <  5 and abs(r-r0)<5:
                    too_close = True
                    break
            if not too_close:
                lines.append((r, t))
                break
            hough_space[r_idx, t_idx] = 0
    #霍夫逆变换
    draw_lines = []
    for r, t in lines:
        a = np.cos(np.deg2rad(t))
        b = np.sin(np.deg2rad(t))
        x0 = a * r
        y0 = b * r
        if t > 45 and t < 135:
            m = -a / b
            c = y0 - m * x0
            x1 = 0
            y1 = int(c)
            x2 = width
            y2 = int(m * width + c)
        else:
            m = -b / a
            c = x0 - m * y0
            y1 = 0
            x1 = int(c)
            y2 = height
            x2 = int(m * height + c)
        draw_lines.append(((x1, y1), (x2, y2)))
    return draw_lines









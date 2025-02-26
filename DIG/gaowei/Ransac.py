import numpy as np


def find_homography_ransac(k1_points, k2_points, num_iterations=500, threshold=5.0):
    best_H = None
    max_inliers = 0

    for i in range(num_iterations):
        # 随机选择4组点
        indices = np.random.choice(len(k1_points), 4, replace=False)
        xy1 = k1_points[indices]
        xy2 = k2_points[indices]

        # 使用随机点计算单应性矩阵
        H = calhomo(xy1, xy2)

        # 计算模型
        inliers = []
        for j in range(len(k1_points)):
            # 变换
            transformed_point = np.dot(H, np.append(k1_points[j], 1))
            transformed_point /= transformed_point[2]  # 转换为非齐次坐标

            # 计算误差
            dist = np.linalg.norm(transformed_point[:2] - k2_points[j])

            # 统计局内数量
            if dist < threshold:
                inliers.append(j)

        # 迭代最佳模型
        if len(inliers) > max_inliers:
            max_inliers = len(inliers)
            best_H = H

    return best_H

def calhomo(xy1,xy2):

    A = []
    for i in range(len(xy1)):
        x, y = xy1[i][0], xy1[i][1]
        u, v = xy2[i][0], xy2[i][1]
        A.append([-x, -y, -1, 0, 0, 0, x * u, y * u, u])
        A.append([0, 0, 0, -x, -y, -1, x * v, y * v, v])
    A = np.asarray(A)

    # SVD解矩阵方程
    U, S, Vt = np.linalg.svd(A)
    H = Vt[-1].reshape(3, 3)

    return H / H[2, 2]
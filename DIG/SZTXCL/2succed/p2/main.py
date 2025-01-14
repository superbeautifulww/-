import cv2
import numpy as np
import matplotlib.pyplot as plt
import mosaic as M
from tkinter import *
from tkinter.filedialog import *
from PIL import Image, ImageTk



file_paths = ["", ""]  # 用一个列表来存储两个文件路径

def choose_picture(button_number):
    global file_paths
    filepath = askopenfilename(title='选择图片文件', initialdir="d", filetypes=[("图片文件", ".tif")])
    if filepath:
        file_paths[button_number - 1] = filepath  # 根据按钮编号存储对应的文件路径
        image = M.open(filepath)
        #image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        image =Image.fromarray(image)
        image = image.resize((320, 240))  # 设置图像大小为300x200（可根据需要调整）
        photo = ImageTk.PhotoImage(image=image)
        if button_number == 1:
            label1.config(image=photo, width=320, height=240)  # 设置Label大小为300x200
            label1.image = photo
        elif button_number == 2:
            label2.config(image=photo, width=320, height=240)  # 设置Label大小为300x200
            label2.image = photo


def solve():
    originimg1, originimg2, img1, img2 = M.process(file_paths[0], file_paths[1])
    img = np.hstack((originimg1,originimg2))
    H = M.get_homo(originimg1,originimg2,img1, img2)
    result_image = M.stitch_image(originimg1, originimg2, H)

    result_image = cv2.cvtColor(result_image, cv2.COLOR_BGR2RGB)  # 将图像转换为RGB格式以便显示
    result_image = Image.fromarray(result_image)
    result_image = result_image.resize((480, 360))
    result_photo = ImageTk.PhotoImage(image=result_image)
    result_label.config(image=result_photo, width=480, height=360)
    result_label.image = result_photo


root = Tk()
root.geometry("1000x800+100+200")
root.title('图像选择程序')

frame = Frame(root)
frame.pack(side='top', pady=5)

Button(frame, text="选择图片1", command=lambda: choose_picture(1)).pack(side='left', padx=100)
Button(frame, text="选择图片2", command=lambda: choose_picture(2)).pack(side='left', padx=100)

label_frame = Frame(root)
label_frame.pack()

label1 = Label(label_frame)
label1.pack(side='left')  # 将 label1 放在 label_frame 的左侧

label2 = Label(label_frame)
label2.pack(side='left')  # 将 label2 放在 label_frame 的左侧


solve_button = Button(root, text="图像拼接",command=solve)
solve_button.pack()  # 将按钮放置在窗口底部，并设置垂直间距

result_label = Label(root)

result_label.pack()  # 将 result_label 放置在窗口中显示 solve() 函数的结果图像

root.mainloop()



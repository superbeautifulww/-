import cv2
import numpy as np
import matplotlib.pyplot as plt
import mosaic as M
from tkinter import *
from tkinter.filedialog import *
from PIL import Image, ImageTk



file_paths = ["", ""]  # 用一个列表来存储两个文件路径
background_path="background.png"

def choose_picture(button_number):
    global file_paths
    global background_path
    filepath = askopenfilename(title='选择图片文件', initialdir="d", filetypes=[("图片文件", ".tif")])
    if filepath:
        #按钮编号对应pathfilename存储顺序，数组记录从0开始，需要-1
        file_paths[button_number - 1] = filepath
        image = M.open(filepath)
        #image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        image =Image.fromarray(image)
        image = image.resize((320, 240))
        photo = ImageTk.PhotoImage(image=image)
        if button_number == 1:
            label1.config(image=photo, width=320, height=240)
            label1.image = photo
        elif button_number == 2:
            label2.config(image=photo, width=320, height=240)
            label2.image = photo
def solve():

    originimg1, originimg2, img1, img2 = M.process(file_paths[0], file_paths[1])
    img = np.hstack((originimg1,originimg2))
    num_iterations = int(iterations_entry.get())
    H = M.get_homo(originimg1,originimg2,img1, img2,num_iterations)
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

#背景图片
backimage = M.open(background_path)
backimage =Image.fromarray(backimage)
backphoto = ImageTk.PhotoImage(image=backimage)

#设置显示初始图像的label1和label2
frame = Frame(root)
frame.pack(side='top', pady=5)

Button(frame, text="选择图片1", command=lambda: choose_picture(1)).pack(side='left', padx=100)
Button(frame, text="选择图片2", command=lambda: choose_picture(2)).pack(side='left', padx=100)

label_frame = Frame(root)
label_frame.pack()

label1 = Label(label_frame)
label1.pack(side='left',padx=5)

label2 = Label(label_frame)
label2.pack(side='left',padx=5)

label1.config(image=backphoto, width=320, height=240)  # 设置Label大小为300x200
label1.image = backphoto

label2.config(image=backphoto, width=320, height=240)  # 设置Label大小为300x200
label2.image = backphoto




iterations_frame = Frame(root)
iterations_frame.pack(pady=5)

#设置显示结果图像的label
solve_button = Button(iterations_frame, text="图像拼接",command=solve)
solve_button.pack(side='left',padx=30)

result_label = Label(root)
result_label.pack()

result_label.config(image=backphoto, width=480, height=360)
result_label.image = backphoto


#输入迭代次数
Label(iterations_frame, text="预测局内点数目：").pack(side='left')
iterations_entry = Entry(iterations_frame)
iterations_entry.pack(side='left')



root.mainloop()



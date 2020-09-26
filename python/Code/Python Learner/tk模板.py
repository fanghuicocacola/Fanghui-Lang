# -*- coding: UTF-8 -*-

# Python2.x 导入方法
from tkinter import *  # 导入 Tkinter 库

# Python3.x 导入方法
# from tkinter import *
root = Tk()  # 创建窗口对象的背景色
# 创建两个列表
li = ['结语', '章节4', '章节3', '章节2', '章节1']
movie = ['第三节', '第二节', '第一节']
list1 = Listbox(root)  # 创建两个列表组件
list2 = Listbox(root)
for item in li:  # 第一个小部件插入数据
    list1.insert(0, item)

for item in movie:  # 第二个小部件插入数据
    list2.insert(0, item)

list1.pack()  # 将小部件放置到主窗口中
list2.pack()
root.mainloop()

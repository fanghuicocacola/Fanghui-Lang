from tkinter import *
from tkinter.messagebox import *


def change(label):
    label['text'] = 'hello world'


def handler(event):
    showinfo("Get it", "Yes")


root = Tk()
lb = Label(root, text='示例文字')
lb.pack()
bt = Button(root, text='Button-I', command=lambda: change(lb))
bt.pack(side=LEFT)
bt2 = Button(root, text='Button-II')
bt2.bind('<Button-1>', handler)
bt2.pack(side=RIGHT)
root.mainloop()
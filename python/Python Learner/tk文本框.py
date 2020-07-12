from tkinter import *

root = Tk()
Label(root, text='作品').grid()
Label(root, text='作者').grid()
e1 = Entry(root)
e2 = Entry(root)
e1.grid(row=0, column=1, padx=10, pady=5)
e2.grid(row=1, column=1, padx=10, pady=5)


def show():
    print('作品：%s' % e1.get())
    print('作者：%s' % e2.get())


Button(root, text='获取', width=10, command=show)\
    .grid(row=3, column=0, sticky=W, padx=10,pady=5)
Button(root, text='退出', width=10, command=root.quit)\
    .grid(row=3, column=1, sticky=E, padx=10, pady=5)
mainloop()


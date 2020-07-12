from tkinter import *


def callback():
    var.set('腊八快乐')


root = Tk()
frame1 = Frame(root)
frame2 = Frame(root)

var = StringVar()
var.set("喝腊八粥了吗？")
textLabel = Label(frame1,
                  textvariable=var,
                  justify=LEFT)
textLabel.pack(side=LEFT)
photo = PhotoImage(file='girl.png')
imgLabel = Label(frame1,image=photo)
imgLabel.pack(side=RIGHT)
theButton = Button(frame2, text='喝了',command=callback)
theButton.pack()
frame1.pack(padx=10, pady=10)
frame2.pack(padx=10, pady=10)
mainloop()
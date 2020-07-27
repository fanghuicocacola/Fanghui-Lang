from tkinter.messagebox import *
from tkinter import *
top = Tk()


def hello():
    showinfo("Say hello","Hello world")


button = Button(top,text="Say hello", command=hello)
button.pack()
top.mainloop()
from tkinter import *

master = Tk()
root = Frame(master)
root.pack(padx=10,pady=10)
v1 = StringVar()
v2 = StringVar()
v3 = StringVar()


def test(content):
    return content.isdigit()


def calc():
    result = int(v1.get()) + int(v2.get())
    v3.set(str(result))


testCMD = root.register(test)

e1 = Entry(root, textvariable=v1, validate='key', validatecommand=(testCMD, '%P')).grid(row=0, column=0)
Label(root, text='+').grid(row=0, column=1)
e2 = Entry(root, textvariable=v2, validate='key', validatecommand=(testCMD, '%P')).grid(row=0, column=2)
Label(root, text='=').grid(row=0, column=3)
e3 = Entry(root, textvariable=v3, validate='key', state='readonly').grid(row=0, column=4)
Button(root,text='calculate',command=calc).grid(row=1,column=2)

mainloop()
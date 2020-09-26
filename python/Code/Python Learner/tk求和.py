from tkinter import *
root = Tk()
root.title('求和')


def cb(event):
    label['text'] = int(text1.get()) + int(text2.get())

label = Label(root,text='0')
label.pack(side=LEFT,padx=60)
text1 = Entry(root)
text2 = Entry(root)
text1.pack(side=LEFT,padx=20)
text2.pack(side=LEFT,padx=30)
button = Button(root,text='求和')
button.bind('<Button-1>',cb)
button.pack()
root.mainloop()



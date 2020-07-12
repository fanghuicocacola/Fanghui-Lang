from tkinter import *

root = Tk()

photo = PhotoImage(file='girl.png')
theLabel = Label(root,
                 text='腊八节',
                 justify=LEFT,
                 image=photo,
                 compound=CENTER,
                 font=(None, 20))
theLabel.pack()
mainloop()

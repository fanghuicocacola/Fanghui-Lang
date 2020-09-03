from tkinter import *

root = Tk()
root.title('腊八节')

photo = PhotoImage(file='girl.png')
theLabel = Label(root,
                 text='腊八节',
                 justify=LEFT,
                 image=photo,
                 compound=CENTER,
                 font=(None, 20))
theLabel.pack()
mainloop()

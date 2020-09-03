from tkinter import *
root = Tk()
root.title('calculate')
root.geometry('500x300')
show = Label(root, text='',font=('宋体', 24), width=20, bg='yellow')
show.pack()
frame = Frame(root)
frame.pack()

result = StringVar()
result.set('')
process = StringVar()
process.set('')

#R0
But_AC = Button(frame, text='清空', width=5).grid(row=0, column=0)
But_cmp = Button(frame, text='=',width=5).grid(row=0, column=1)
BUTNULL=Button(frame,text='Null',width=5).grid(row=0,column=2)
BUTNULL2=Button(frame,text='Null',width=5).grid(row=0,column=3)

# R1
But_point = Button(frame, text='.',width=5).grid(row=1, column=0)
But0 = Button(frame, text='0',width=5).grid(row=1, column=1)
But_back = Button(frame, text='退位',width=5).grid(row=1, column=2)
But_division = Button(frame, text='/',width=5).grid(row=1, column=3)

# R2
But1 = Button(frame, text='1',width=5).grid(row=2,column=0)
But2 = Button(frame, text='2',width=5).grid(row=2,column=1)
But3 = Button(frame, text='3',width=5).grid(row=2,column=2)
But_multi = Button(frame, text='*',width=5).grid(row=2,column=3)

# R3
But4 = Button(frame, text='4',width=5).grid(row=3,column=0)
But5 = Button(frame, text='5',width=5).grid(row=3,column=1)
But6 = Button(frame, text='6',width=5).grid(row=3,column=2)
But_sub = Button(frame, text='-',width=5).grid(row=3,column=3)

# R4
But7 = Button(frame, text='7',width=5).grid(row=4,column=0)
But8 = Button(frame, text='8',width=5).grid(row=4,column=1)
But9 = Button(frame, text='9',width=5).grid(row=4,column=2)
But_add = Button(frame, text='+',width=5).grid(row=4,column=3)



Flag = 0


def press(x):
    global Flag
    if Flag:
        result.set("")
        process.set('')
        Flag = 0
    if x == 'AC':
        if result.get() == "":
            return
        result.set("")
        process.set('')
        return
    if x == 'b':
        if result.get() == "":
            return
        temp = result.get()[0:-1]
        if temp == '':
            result.set('')
        else:
            result.set(temp)
        return
    if result.get() != '':
        result.set(result.get() + x)
    else:
        result.set(x)


def comput():
    expression = result.get()
    ans = eval(expression)
    process.set(expression + "=")
    if isinstance(ans, float):
        ans = round(ans, 6)
    result.set(ans)
    global Flag
    Flag = 1



menu = Menu(root)
f_menu = Menu(menu)
f_menu.add_command(label='QUIT', command=root.quit)
f_menu.add_command(label='退出', command=root.quit)
menu.add_cascade(label='菜单', menu=f_menu)
root['menu'] = menu
root.mainloop()
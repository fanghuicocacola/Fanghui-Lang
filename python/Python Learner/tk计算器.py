from tkinter import *

root = Tk()
root.title("计算器")
root.geometry("340x740")
menu = Menu(root)
fmenu = Menu(menu)
fmenu.add_command(label='退出',command=root.quit)

result = StringVar()
result.set('')
process = StringVar()
process.set('')
# R0
But_AC = Button(root, text='清空', command=lambda: press('AC')).place(x=0, y=620, width=100, height=100)
But_cmp = Button(root, text='=', command=lambda: comput()).place(x=100, y=620, width=240, height=100)

# R1
But_point = Button(root, text='.', command=lambda: press('.')).place(x=0, y=620 - 1 * 80, width=80, height=80)
But0 = Button(root, text='0', command=lambda: press('0')).place(x=0 + 1 * 80, y=620 - 1 * 80, width=80, height=80)
But_back = Button(root, text='退位', command=lambda: press('b')).place(x=0 + 2 * 80, y=620 - 1 * 80, width=80, height=80)
But_division = Button(root, text='/', command=lambda: press('/')).place(x=0 + 3 * 80, y=620 - 1 * 80, width=100, height=80)
# R2
But1 = Button(root, text='1', command=lambda: press('1')).place(x=0, y=620 - 2 * 80, width=80, height=80)
But2 = Button(root, text='2', command=lambda: press('2')).place(x=0 + 1 * 80, y=620 - 2 * 80, width=80, height=80)
But3 = Button(root, text='3', command=lambda: press('3')).place(x=0 + 2 * 80, y=620 - 2 * 80, width=80, height=80)
But_multi = Button(root, text='*', command=lambda: press('*')).place(x=0 + 3 * 80, y=620 - 2 * 80, width=100, height=80)
# R3
But4 = Button(root, text='4', command=lambda: press('4')).place(x=0, y=620 - 3 * 80, width=80, height=80)
But5 = Button(root, text='5', command=lambda: press('5')).place(x=0 + 1 * 80, y=620 - 3 * 80, width=80, height=80)
But6 = Button(root, text='6', command=lambda: press('6')).place(x=0 + 2 * 80, y=620 - 3 * 80, width=80, height=80)
But_sub = Button(root, text='-', command=lambda: press('-')).place(x=0 + 3 * 80, y=620 - 3 * 80, width=100, height=80)
# R4
But7 = Button(root, text='7', command=lambda: press('7')).place(x=0, y=620 - 4 * 80, width=80, height=80)
But8 = Button(root, text='8', command=lambda: press('8')).place(x=0 + 1 * 80, y=620 - 4 * 80, width=80, height=80)
But9 = Button(root, text='9', command=lambda: press('9')).place(x=0 + 2 * 80,y=620 - 4 * 80,  width=80, height=80)
But_add = Button(root, text='+', command=lambda: press('+')).place(x=0 + 3 * 80, y=620 - 4 * 80, width=100, height=80)

Label(root, anchor='se', textvariable=result).place(y=200, width=340, height=50)
Label(root, anchor='se',  textvariable=process).place(width=340, height=200)

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


menu.add_cascade(label='菜单', menu=fmenu)
root['menu'] = menu
root.mainloop()
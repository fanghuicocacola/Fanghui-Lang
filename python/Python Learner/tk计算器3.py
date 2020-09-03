from tkinter import *
import math
root = Tk()
root.title('calculate')
root.geometry('500x300')
show = Label(root, text='',font=('宋体', 24), width=20, bg='yellow')
show.pack()
frame = Frame(root)
frame.pack()


def click(event):
    if event.widget['text'] in ('1','2','3','4','5','6','7','8','9','0','.','*','/','-','+'):
        show['text'] = show['text'] + event.widget['text']
    elif event.widget['text'] == '=' and show['text'] is not None:
        show['text'] = str(eval(show['text']))
    elif event.widget['text'] == '清零':
        show['text'] = ''
    elif event.widget['text'] == 'sqrt':
        show['text'] = str(math.sqrt(int(show['text'])))


name = ['清空','=','Null','Null2','.','退位','0','/','1','2','3','*','4','5','6','-','7','8','9','+','sqrt']

for i in range(len(name)):
    button = Button(frame, text=name[i], width=5)
    button.grid(row=i//4, column=i%4)
    button.bind('<Button-1>', click)

menu = Menu(root)
f_menu = Menu(menu)
f_menu.add_command(label='QUIT', command=root.quit)
f_menu.add_command(label='退出', command=root.quit)
menu.add_cascade(label='菜单', menu=f_menu)
root['menu'] = menu
root.mainloop()
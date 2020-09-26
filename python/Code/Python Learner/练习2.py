from tkinter import *
import math
ii = 1


class A:
    def __init__(self):
        self.root = Tk()
        self.root.geometry('500x300')
        self.root.title('calculate')
        if ii == 1:
            self.calwidget()
        menu = Menu(self.root)
        f_menu = Menu(menu)
        f_menu.add_command(label='QUIT', command=self.root.quit)
        f_menu.add_command(label='退出', command=self.root.quit)
        menu.add_cascade(label='菜单', menu=f_menu)
        menu.add_cascade(label='联系方式')
        self.root['menu'] = menu
        self.root.mainloop()

    def calwidget(self):
        self.show = Label(self.root, text='', font=('宋体', 24), width=20, bg='yellow')
        self.show.pack()
        self.frame = Frame(self.root)
        self.frame.pack()
        name = ['清空', '=', 'Null', 'Null2', '.', '退位', '0', '/', '1', '2', '3', '*', '4', '5', '6', '-', '7', '8', '9', '+', 'sqrt','下一页']
        for i in range(len(name)):
            button = Button(self.frame, text=name[i], width=5)
            button.grid(row=i // 4, column=i % 4)
            button.bind('<Button-1>', self.click)

    def again(self):
        self.root.destroy()

    def command(self):
        self.frame.destroy()
        self.frame = Frame(self.root)
        self.frame.pack()
        name2 = ['结束', '上一页']
        button2 = Button(self.frame, text='结束', width=5)
        button2.grid(row=0, column=0)
        button2.bind('<Button-1>', sys.exit)
        button3 = Button(self.frame, text='上一页', width=5)
        button3.grid(row=0, column=1)
        button3.bind('<Button-1>', self.again)

    def click(self, event):
        if event.widget['text'] in ('1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', '*', '/', '-', '+'):
            self.show['text'] = self.show['text'] + event.widget['text']
        elif event.widget['text'] == '=' and self.show['text'] is not None:
            self.show['text'] = str(eval(self.show['text']))
        elif event.widget['text'] == '清空':
            self.show['text'] = ''
        elif event.widget['text'] == '退位':
            self.show['text'] = self.show['text'][0:-1]
        elif event.widget['text'] == 'sqrt':
            self.show['text'] = str(math.sqrt(float(self.show['text'])))
        elif event.widget['text'] == '下一页':
            global ii
            ii = 0
            self.command()


A()

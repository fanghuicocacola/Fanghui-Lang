from tkinter import *
import random
import sys
from tkinter import messagebox


code = ''
for i in range(0,4):
    w = random.choice([chr(random.randrange(65,91)),random.randrange(10)])
    code += str(w)


class Login(object):
    def __init__(self):
        self.root = Tk()
        self.root.title('管理系统')
        self.root.geometry('700x600')
        self.canvas = Canvas(self.root, height=500, width=600)
        self.image = PhotoImage(file='sun.gif')
        self.canvas.pack(side='top')
        self.name = Label(self.root, text='用户名')
        self.password = Label(self.root, text='密码')
        self.vcode = Label(self.root, text='验证码'+code)

        self.inputname = Entry(self.root, width=30)
        self.inputpass = Entry(self.root, show='*', width=30)
        self.inputvcode = Entry(self.root, width=15)

        self.login_button = Button(self.root, command=self.backstage_interface, text="登录", width=10)
        self.siginUp_button = Button(self.root, command=self.siginUp_interface, text="注册", width=10)
        self.quit = Button(self.root,command=self.quit,text='退出', width=10)

    def gui_arrang(self):
        self.name.place(x=60, y=50)
        self.password.place(x=60, y=75)
        self.vcode.place(x=60, y=100)
        self.inputname.place(x=110, y=50)
        self.inputpass.place(x=110, y=75)
        self.inputvcode.place(x=150, y=100)
        self.login_button.place(x=120, y=150)
        self.siginUp_button.place(x=220, y=150)
        self.quit.place(x=320, y=150)


    def siginUp_interface(self):
        # 有空加上录入
        messagebox.showinfo(title='欢迎',message='注册成功')


    def backstage_interface(self):
        # 有空加上验证
        account = self.inputname.get().ljust(10, " ")
        password = self.inputpass.get().ljust(10, " ")
        messagebox.showinfo(title='测试系统', message='录入账户:{}\n密码：{}\n登录成功！'.format(account, password))


    def quit(self):
        sys.exit()




L = Login()
L.gui_arrang()
mainloop()











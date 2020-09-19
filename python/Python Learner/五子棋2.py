# 导入相关包
from tkinter import *
from tkinter.messagebox import *
import math
# 分别定义两个五子棋和计算器两个类


class Wzq:
    def __init__(self):
        # 创建一个初始化界面的窗口
        self.root = Tk()
        self.root.geometry('600x650')
        self.pic = PhotoImage(file='ball.png')
        # 铺设一个画布
        self.r = Canvas(self.root, width=797, height=1380)
        self.r.pack()
        self.r.create_image(100, 690, image=self.pic)
        self.last = None
        # 创建几个按钮并且绑定运行五子棋，计算器命令和退出命令
        b1 = Button(self.root, text='五子棋', width=10)
        b1.pack()
        b1.place(x=200, y=580)
        b1.bind('<Button-1>', self.click1)
        b2 = Button(self.root, text='退出',width=10,command=self.root.destroy)
        b2.pack()
        b2.place(x=300, y=580)
        b3 = Button(self.root, text='计算器', width=10, height=1)
        b3.pack()
        b3.place(x=250,y=540)
        b3.bind('<Button-1>', self.click2)
        self.root.mainloop()

    # 五子棋对应函数
    def click1(self,event):
        # 检测是否被执行
        print('1')
        # 命名标签
        self.label = Label(self.root,text ='游戏开始',fg = 'pink')
        self.label.pack()
        # 摧毁上一个画布并新铺设一个
        self.r.destroy()
        self.c = Canvas(self.root, width=460,height=460,bg='pink')
        self.c.pack()
        self.c.place(x=20,y=20)
        # 画棋盘
        for i in range(1,16):
            self.c.create_line(30,30*i,450,30*i)
            self.c.create_line(30*i,30,30*i,450)
        for i in range(30,451,30):
            for j in range(30,451,30):
                self.c.create_oval(i-2,j-2,i+2,j+2)
        # 为棋盘上每个格点绑定鼠标事件（左键落黑子，右键落白子）
        self.c.bind('<Button-1>',self.callback1)
        self.c.bind('<Button-3>', self.callback2)
        # 定义一个二维数组
        self.matrix = [[0 for y in range(15)] for x in range(15)]
        self.c.mainloop()

    # 黑子事件
    def callback1(self,event):
        u,v = event.x,event.y
        for i in range(1,16):
            if 15*i < u < 15*(2*i+1):
                zx = i-1
                break
        for i in range(1,16):
            if 15 * i < v < 15 * (2 * i + 1):
                zy = i - 1
                break
        # 标记黑子坐标为1
        self.matrix[zx][zy] = 1
        # 画黑子
        self.c.create_oval((zx+1)*30-12, (zy+1)*30-12, (zx+1)*30+12, (zy+1)*30+12, fill='black')
        win = self.panfan(zx, zy)
        # 根据panfen（）函数确定输赢 panfen返回1是黑赢，-1则是白
        if win == 1:
            # 小窗口输出黑方胜利
            answer = showinfo('Game over','黑方赢')
            self.click1(event)

    # 白子事件
    def callback2(self,event):
        u,v = event.x,event.y
        for i in range(1,16):
            if 15*i < u < 15*(2*i+1):
                zx = i-1
                break
        for i in range(1,16):
            if 15 * i < v < 15 * (2 * i + 1):
                zy = i - 1
                break
        # 标记白子坐标为-1
        self.matrix[zx][zy] = -1
        # 画白字
        self.c.create_oval((zx+1)*30-12,(zy+1)*30-12,(zx+1)*30 +12,(zy+1)*30 +12,fill = 'white')
        win = self.panfan(zx, zy)
        # 根据panfen（）函数确定输赢 panfen返回1是黑赢，-1则是白
        if win == -1:
            # 小窗口输出白方胜利
            answer = showinfo('Game over','白方赢')
            self.click1(event)

    # 判分函数
    def panfan(self, x, y):
            # 检测斜方向的落子情况
            def direction(x, y, dx, dy, row, column, matrix):
                temp = []
                while 0 <= x < row and 0 <= y < column:
                    x, y = x + dx, y + dy
                x, y = x - dx, y - dy
                while 0 <= x < row and 0 <= y < column:
                    temp.append(matrix[x][y])
                    x, y = x - dx, y - dy
                return temp
            # 记录四个方向的落子情况
            four_direction = []
            four_direction.append([self.matrix[i][y] for i in range(15)])
            four_direction.append([self.matrix[x][j] for j in range(15)])
            four_direction.append(direction(x,y,1,1,15,15,self.matrix))
            four_direction.append(direction(x, y, 1,-1, 15, 15, self.matrix))
            # 根据记录检测是否五子连珠
            for v_list in four_direction:
                    count1 = 0
                    count2 = 0
                    for v in v_list:
                        if v == 1:
                            count1 += 1
                            if count1 == 5:
                                return 1
                        elif v == -1:
                            count2 += 1
                            if count2 == 5:
                                return -1

    # 切换到计算器界面
    def click2(self,event):
        self.root.destroy()
        Jsq()

class Jsq:
    def __init__(self):
        # 创建窗口
        self. root =Tk()
        # 创建菜单
        self.menu = Menu(self.root)
        self.fmenu = Menu(self.menu)
        self.root.geometry('444x666')
        # 运行ap（）函数，创建一个frame框架
        self.ap()
        for item in ['文件', '编辑']:
            self.menu.add_command(label=item, command=self.callbac)
        for item in ['文件', '编辑']:
            self.fmenu.add_command(label=item)
        self.menu.add_cascade(label='菜单',menu = self.fmenu)
        self.root['menu'] = self.menu
        self.root.mainloop()
    # 上面菜单的一个标签绑定的事件
    def callbac(self):
        print('this is menu')
    # 创建frame框架
    def ap(self):
        self.show = Label(self.root, width=24,bg='pink')
        self.show.pack()
        self.ck = Entry(self.root, width=12,font=('楷体', 32))
        self.ck.pack()
        p = Frame(self.root)
        p.pack()
        # 用for循环创建按钮，并绑定事件
        name = ('1','2','3','4','5','6','7','8','9','0',
                '.','*','%','/','**','//','-','+','sqrt','=','清除','退位','sqrt')
        for i in range(len(name)):
            b = Button(p,text=name[i],width=6,height=2,bg='yellow')
            b.grid(row=i//5,column=i%5)
            b.bind('<Button-1>',self.click)

        # 按钮对应的事件函数
    def click(self,event):
        if (event.widget['text'] in ('1','2','3','4','5','6','7','8','9','0','.','*','%','/','**','//','-','+')):
            self.show['text'] = self.show['text'] + event.widget['text']
        elif event.widget['text'] == '=' and self.show['text'] is not None:
            self.show['text'] = str(eval(self.show['text']))
        elif event.widget['text'] == '退位':
            self.show['text'] = self.show['text'][0:-1]
        elif event.widget['text'] == 'sqrt':
            self.show['text'] = str(math.sqrt(float(self.show['text'])))
            self.ck.insert(-1,self.show['text'])
        elif event.widget['text'] == '清除':
            self.show['text'] = ''

if __name__ == '__main__':
    Wzq()
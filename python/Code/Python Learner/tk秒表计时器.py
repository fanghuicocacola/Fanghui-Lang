from tkinter import *
import time
import sys

class Clock(Frame):
    def __init__(self):
        Frame.__init__(self)
        self.start = 0.0              # 私有 开始时间设为 0
        self.passtime = 0.0           # 已经过去了的时间设为 0
        self.isRunning = False        # 秒表是否在运行 默认为否
        self.timestr = StringVar()     # 时间字符串
        self.layout()                  # 图形界面布局


    def quit(self):
        sys.exit()

    def layout(self):
        lab = Label(self, textvariable=self.timestr, font=100)
        self.setTime(self.passtime)
        lab.pack(fill="x", pady=20)


    def setTime(self, passTime):
        min = int(passTime/60)
        sec = int(passTime - min * 60.0)
        msec = int((passTime - min * 60.0 - sec) * 10)
        self.timestr.set('%02d:%02d.%01d' % (min, sec, msec))


    def update(self):
        self.passtime = time.time() - self.start
        self.setTime(self.passtime)
        self.timer = self.after(100, self.update)     # 每 100ms 更新一次


    def begin(self):
        if not self.isRunning:
            self.start = time.time() - self.passtime
            self.update()
            self.isRunning = True


    def stop(self):
        if self.isRunning:
            self.after_cancel(self.timer)
            self.passtime = time.time() - self.start
            self.setTime(self.passtime)
            self.isRunning = False


    def reset(self):
        if not self.isRunning:           # 设置只有在秒表停止后 reset 才起作用
            self.start = time.time()
            self.passtime = 0.0
            self.setTime(self.passtime)


myclock = Tk()
do = Clock()
width = 320
height = 96
screenwidth = myclock.winfo_screenwidth()
screenheight = myclock.winfo_screenheight()
position = '%dx%d+%d+%d' % (width, height, (screenwidth-width)/2, (screenheight-height)/2)
myclock.geometry(position)
myclock.title("秒表计时器")
do.pack(side=TOP)
b1 = Button(myclock, text='开始', command=do.begin)
b1.pack(fill="x", expand=1, side=LEFT)
b2 = Button(myclock, text='停止', command=do.stop)
b2.pack(fill="x", expand=1, side=LEFT)
b3 = Button(myclock, text='重置', command=do.reset)
b3.pack(fill="x", expand=1, side=LEFT)
b4 = Button(myclock, text='退出', command=do.quit)
b4.pack(fill="x", expand=1, side=LEFT)
myclock.mainloop()



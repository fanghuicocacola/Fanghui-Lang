from tkinter import *
from tkinter.messagebox import *


class A(object):
    def __init__(self):
        self.root = Tk()
        self.image = PhotoImage(file='ball.png')
        self.root.geometry('500x510')
        self.cv = Canvas(self.root, width=520, height=460)
        self.cv.pack()
        self.cv.create_image(100, 100, image=self.image)
        self.button1 = Button(self.root, text='开始/重来', width=10)
        self.button1.pack()
        self.button1.place(x=150, y=480)
        self.button1.bind('<Button-1>', self.start)
        self.button2 = Button(self.root, text='结束', width=10)
        self.button2.pack()
        self.button2.place(x=300, y=480)
        self.button2.bind('<Button-1>', self.end)
        self.root.mainloop()

    def start(self,event):
        self.cv.destroy()
        self.cv = Canvas(self.root, width=460, height=460, bg='yellow')
        self.cv.pack()
        self.cv.place(x=20, y=20)
        for i in range(1, 16):
            self.cv.create_line(30, 30*i, 450, 30*i)
            self.cv.create_line(30*i, 30, 30*i, 450)
        for i in range(30, 451, 30):
            for j in range(30,451,30):
                self.cv.create_oval(i-2, j-2, i+2, j+2, fill='blue')
        self.cv.bind('<Button-1>', self.callback1)
        self.cv.bind('<Button-3>', self.callback2)
        self.matrix = [[0 for y in range(15)] for x in range(15)]

    def end(self, over):
        sys.exit()

    def callback1(self, event):
        u, v = event.x, event.y
        for i in range(1, 16):
            if 15*i < u < 15 * (2*i+1):
                zx = i - 1
                break
        for i in range(1, 16):
            if 15*i < v < 15 * (2*i+1):
                zy = i - 1
                break
        self.matrix[zx][zy] = 1
        self.cv.create_oval((zx+1)*30-12,(zy+1)*30-12,(zx+1)*30+12,(zy+1)*30+12,fill='BLACK')
        win = self.is_win(zx,zy)
        if win == TRUE:
            showinfo('BLACK WIN')

    def callback2(self, event):
        u, v = event.x, event.y
        for i in range(1, 16):
            if 15 * i < u < 15 * (2 * i + 1):
                zx = i - 1
                break
        for i in range(1, 16):
            if 15 * i < v < 15 * (2 * i + 1):
                zy = i - 1
                break
        self.matrix[zx][zy] = -1
        self.cv.create_oval((zx + 1) * 30 - 12, (zy + 1) * 30 - 12, (zx + 1) * 30 + 12, (zy + 1) * 30 + 12,
                            fill='WHITE')
        win = self.is_win(zx,zy)
        if win == FALSE:
            showinfo('WHITE WIN','win!')

    def is_win(self, x, y):
        def direction(i, j, di, dj, row, column, matrix):
            temp = []
            while 0 <= i < row and 0 <= j < column:
                i, j = i + di, j + dj
            i, j = i - di, j - dj
            while 0 <= i < row and 0 <= j < column:
                temp.append(matrix[i][j])
                i, j = i - di, j - dj
            return temp

        four_direction = []
        four_direction.append([self.matrix[i][y] for i in range(15)])
        four_direction.append([self.matrix[x][j] for j in range(15)])
        four_direction.append(direction(x, y, 1, 1, 15, 15, self.matrix))
        four_direction.append(direction(x, y, 1, -1, 15, 15, self.matrix))
        for i in four_direction:
            count1 = 0
            count2 = 0
            for v in i:
                if v == 1:
                    count1 += 1
                    if count1 == 5:
                        return True
                elif v == -1:
                    count2 += 1
                    if count2 == 5:
                        return FALSE
        return False


if __name__ == "__main__":
    A()
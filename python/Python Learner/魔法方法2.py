import time as t


class A:
    def __str__(self):
        return "多喝热水！"


a = A()
print(a)


class Timer:
    def __init__(self):
        self.prompt = "未计时"
        self.unit = ['y', 'm', 'd', 'h', 'min','sec']
        self.lasted = []
        self.start = 0
        self.stop = 0

    def Tstart(self):
        self.start = t.localtime()
        print("GO!")

    def Tstop(self):
        self.stop = t.localtime()
        self.calc()
        print("STOP!")

    def calc(self):
        self.lasted = []
        self.prompt = "运行时间"
        for index in range(6):
            self.lasted.append(self.stop[index] - self.start[index])
            self.prompt += str(self.lasted[index])
        if self.lasted[index]:
            self.prompt += (str(self.lasted[index]) + self.unit[index])
        print(self.prompt)


t1 = Timer()
t1.Tstart()
t.sleep(3)
t1.Tstop()
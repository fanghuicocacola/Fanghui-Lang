class A:
    def __init__(self,x,y):
        self.x = x
        self.y = y

    def G1(self):
        return (self.x + self.y)*2

    def G2(self):
        return self.x * self.y


a = A(3,4)
print(a.G1())
print(a.G2())


class B(str):
    def __new__(cls, string):
        string = string.upper()
        return str.__new__(cls,string)


a = B("never give up")
print(a)


class C:
    def __init__(self):
        print("我是_init_")

    def __del__(self):
        print('我是_del_')


a = C()
print(a)
del a


class D(int):
    def __add__(self, other):
        return int.__sub__(self, other)

    def __sub__(self, other):
        return int.__add__(self, other)


a = D(1)
b = D(5)
print("这是一个恶作剧", a, '+', b, '=', end=' ')
print(a+b)
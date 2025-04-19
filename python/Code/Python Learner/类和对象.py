

class MyList(list):
    pass


list2 = MyList()
list2.append(1)
list2.append('a')
print(list2)


class A:
    def f(self):
        print("我是A")


a = A()
a.f()


class Ball:
    name = 'aaa'

    def __init__(self, format_spec):
        self.format_spec = format_spec

    def kick(self):
        print("%s" % self.format_spec)


class BB:
    def ff(self, name):
        self.name = name

    def kick(self):
        print("%s" % self.name)


class Person:
    __name = 'daka'

    def Getname(self):
        return self.__name


p = Person()
print(p.Getname(),p._Person__name)
a = Ball('tu')
a.kick()
print(a.name)
b = BB()
b.ff('dou')
b.kick()

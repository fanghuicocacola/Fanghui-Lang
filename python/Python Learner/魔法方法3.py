class MyDirect:
    def __get__(self, instance, owner):
        print("getting...", self, instance, owner)

    def __set__(self, instance, value):
        print("setting", self, instance, value)

    def __delete__(self, instance):
        print("delating...", self, instance)


class Text:
    x = MyDirect()


text = Text()
text.x
text.x = 'XXX'
del text.x


class Project:
    def __init__(self, fget = None, fset = None, fdel = None):
        self.fget = fget
        self.fset = fset
        self.fdel = fdel

    def __get__(self, instance, owner):
        return self.fget(instance)

    def __set__(self, instance, value):
        self.fset(instance,value)

    def __delete__(self, instance):
        self.fdel(instance)


class P:
    def __init__(self):
        self._x = None

    def getx(self):
        return self._x

    def setx(self, value):
        self._x = value

    def delx(self):
        del self._x

    x = Project(getx, setx, delx)


p = P()
p.x = "x-man"
print(p.x, p._x)


class CountList:
    def __init__(self,*args):
        self.values = [x for x in args]
        self.counts = {}.fromkeys(range(len(self.values)), 0)

    def __len__(self):
        return len(self.values)

    def __getitem__(self, key):
        self.counts[key] += 1
        return self.values[key]


c1 = CountList(1,3,5,7,9)
print(c1[1])
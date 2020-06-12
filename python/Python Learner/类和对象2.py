class A:
    def x(self):
        print("x-man")


a = A()
a.x()
a.x = 1
print(a.x)


class B:
    def set(self, x, y):
        self.x = x
        self.y = y
    def printxy(self):
        print(self.x,self.y)


aa = B()
aa.set(1, 2)
aa.printxy()
print(aa.__dict__)


class C:
    def __init__(self,x='great'):
        self.x = x
    def getsize(self):
        return self.x
    def setsize(self,value):
        self.x = value
    def delsize(self):
        del self.x
    z = property(getsize,setsize,delsize)


bb = C()
print(hasattr(bb, 'x'))
print(getattr(bb, 'x'))
setattr(bb,'y', '你所访问的不存在')
print(bb.y)
delattr(bb, 'x')
cc = C()
print(cc.getsize(), cc.x, cc.z)
cc.z = 'good'
print(cc.x,cc.getsize())

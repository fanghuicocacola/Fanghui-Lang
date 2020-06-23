def MyGen():
    print("生成器被执行")
    yield 1
    print("被执行")
    yield 2


def Libs():
    a = 0
    b = 1
    while True:
        a, b = b, a + b
        yield a


MG = MyGen()
next(MG)
next(MG)
for each in Libs():
    if each > 100:
        break
    print(each, end=" ")

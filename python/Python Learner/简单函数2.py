
a = [1, 2, 3, 4, 5]
b = [1, 2, 4, 5]
c = ['sad', 1]
d = list(zip(a, b))
print(d)
print(list(zip(*d)))


def dt(num1, num2, num3):
    k = num2 ^ 2 - 4 * num1 * num3
    print(k)


dt(2, 1, 1)


def kk(str1='马丁路德金', str2='我有一个梦想'):
    print(str1 + 'said' + str2)


kk('有人')


def aa(*p):
    print(len(p))
    print(p[0])


aa('never', 111, 22, 'give', 'up')

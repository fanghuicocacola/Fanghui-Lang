def jc(a):
    if a <= 1:
        return 1
    else:
        return a*jc(a-1)


def js(a):
    y = 1
    for n in range(2,8,1):
        if n < 8:
            y += a**n / n
    return y


def zc(a):
    for i in range(1,a,1):
        if a % i == 0:
            print(i)


x = int(input())

print(jc(x))
print(js(x))
zc(x)
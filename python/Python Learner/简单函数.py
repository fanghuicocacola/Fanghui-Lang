# 递增解法
def func(n):
    a, b = 1, 2
    for i in range(n + 1):
        c = a
        a = b
        b = c*b
    return a


print(1, end=' ')
for i in range(1, 10, 1):
    print(func(i), end=' ')



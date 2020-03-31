import math
Sum = 1
t = 1
x = int(input())
for i in range(1, 100):
    t = t*i
    Sum = Sum + x**i/t
    if x**i/t < 10**-22:
        print(i)
        break
print('{:.21f}'.format(Sum))
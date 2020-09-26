# 求一元二次方程的根
import math
a = float(input("请输入a "))
b = float(input("请输入b "))
c = float(input("请输入c "))
if a != 0:
    r = b**2 - 4*a*c
    if r < 0:
        print("虚根")
    elif r == 0:
        x = -b/2*a
        print("唯一解为", x)
    elif r > 0:
        x1 = (-b+math.sqrt(r))/(2*a)
        x2 = (-b-math.sqrt(r))/(2*a)
        print("两1解为", x1, x2)
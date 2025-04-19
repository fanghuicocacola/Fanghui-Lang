import math
x = int(input('x :'))
z = int(input('z :'))
if z > 0:
    if x >= 5:
        y = math.sqrt(x) + z
    elif 0 < x < 5:
        y = x**3 + z
    elif x == 0:
        y = z
    elif x < 0:
        y = -2/x + z
    print("y = ",y)
elif z < 0:
    if x >= 5:
        y = math.sqrt(x) - z
    elif 0 < x < 5:
        y = x**3 - z
    elif x == 0:
        y = z
    elif x < 0:
        y = -2/x - z
    print("y = ", y)
else:
    print("不计算")


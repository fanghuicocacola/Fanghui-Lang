import math
a = float(input('length of size\n'))
b = float(input())
c = float(input())
p = (a+b+c)/2
if a+b > c and a+c > b and b+c > a:
    s = math.sqrt(p*(p-a)*(p-b)*(p-c))
    print(" 面积", "{:.2f}".format(s))
else:
    print("不是三角形")

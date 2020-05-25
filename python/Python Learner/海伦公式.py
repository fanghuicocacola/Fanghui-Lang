import math
p = 0
s = 0
print("请依次输入三条边的长度（回车）")
a = float(input())
b = float(input())
c = float(input())
p = (a+b+c)/2
s = math.sqrt(p*(p-a)*(p-b)*(p-c))
print(p,s)


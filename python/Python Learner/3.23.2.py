
a = int(input('输入一个三位数'))
bw = a//100
sw = (a % 100)//10
gw = (a % 10)
b = gw**3+sw**3+bw**3

if a == b:
    print(a, "是水仙花数")
else:
    print(a, "不是水仙花数")
s = []
n = int(input('增加N个学生信息： '))
for i in range(1, n+1, 1):
    d1 = {}
    name = str(input('输入姓名：'))
    math = input('输入数学: ')
    en = input('输入英语： ')
    d1.update({'姓名': name, '数学': math, '英语': en})
    s.append(d1)
print(s)
sn = str(input("请输入删除姓名："))

for i in s:
    for v in i.values():
        if v == sn:
            s.remove(i)

print(s)






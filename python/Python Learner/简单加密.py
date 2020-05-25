n = input('请输入学号后两位：')
str1 = 'python'+str(n)
print(str1)
N = abs(ord(n[0])-ord(n[1]))
new = ''
for i in str1:
    asc = ord(i)
    str2 = chr(asc+N)
    new = new + str2
jm = new[::-1]
print('密文是：', jm)



s = 'boys are good,boys like VS'
# 方法一
s1 = ''
s2 = s.split()
n = 0
for i in s:
    if i.isalnum() or i == ' ':
        s1 = s1 + i
    else:
        i = ' '
        s1 = s1 + i
print(s1)
s2 = s1.split()
for i in s2:
    if 'boys' in i:
        n += 1
print(n)
# 方法二
n = s1.count("boys", 0)   # 统计字符串中 \\ 出现的次数
print(n)
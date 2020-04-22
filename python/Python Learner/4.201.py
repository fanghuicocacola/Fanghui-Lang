str1 = 'boys are good,boys like VS'
# 方法一
str2 = str1.split()
n = 0
for i in str2:
    if 'boys' in i:
        n += 1
print(n)
# 方法二
n = str1.count("boys", 0)   # 统计字符串中 \\ 出现的次数
print(n)
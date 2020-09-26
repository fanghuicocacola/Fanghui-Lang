s = ['张一华，男，45', '王二菲，女，65', '张飞，男，78', '李翠，女，56']
s1 = []
for i in s:
    str1, str2, str3 = i.split('，', 2)
    str3 = int(str3)
    if str3 < 60 and str2 == '男':
        s1.append(i)
print('不及格的男生有：', s1)

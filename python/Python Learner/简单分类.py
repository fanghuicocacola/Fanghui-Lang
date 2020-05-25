s = ['张一华，男', '王二菲，女', '张飞，男', '李四，男']
s1 = []
s2 = []
for i in s:
    if i[-1] == '男':
        s1.append(i)
    else:
        s2.append(i)
print(s1)
print(s2)

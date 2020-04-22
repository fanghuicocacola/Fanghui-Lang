s = [['张三', 94], ['李四', 66], ['王五', 77]]
for i in s:
    if i[1] < 60:
        i.append('不及格')
    elif 60 <= i[1] <= 75:
        i.append('及格')
    elif 75 < i[1] <= 85:
        i.append('良好')
    elif i[1] > 85:
        i.append('优秀')
print(s)
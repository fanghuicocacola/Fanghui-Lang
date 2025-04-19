s = {'姓名': '小明', '数学': '66', '化学': '44'}
print(s)
m = []
for k, v in s.items():
    if k != '姓名':
        if int(v) < 60:
            m.append(k)
for i in m:
    s.pop(i)
print(s)


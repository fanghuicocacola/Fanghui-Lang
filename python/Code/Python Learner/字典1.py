d = {'name': 'tony', 'math': '56', 'en': '68', 'py': '73'}
print(d['name'], 'math:', d['math'])
s = ['name:tony', 'math:56', 'en:68', 'py:73']
for i in s:
    j = i.split(':')
    if j[0] == 'name':
        name = j[1]
    if j[0] == 'math':
        math = int(j[1])
print(name+'数学：', math)
s = {'姓名': '小明', '生物': '92', '化学': '82'}
a = s['生物']
b = s['化学']
s['总分'] = int(a)+int(b)
s['平均分'] = (int(a)+int(b))/2
if s['总分'] > 120:
    s.update({'总分': '合格'})
print(s)


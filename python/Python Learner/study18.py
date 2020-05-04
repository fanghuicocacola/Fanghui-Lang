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
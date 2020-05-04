d = {'name': '张三',  '足球': '1', '篮球': '0', '排球': '1', '乒乓球': '0'}
s = []
n = 0
for k, v in d.items():
    if k != 'name' and v == '1':
        s.append([k, v])
        n = n + 1
print(s, n)
d = {'name': 'tony', 'math': '56', 'en': '68', 'py': '73'}
n = 0
for i in d.items():
    if i[0] != 'name' and int(i[1]) < 60:
          n = n+1
print(n)

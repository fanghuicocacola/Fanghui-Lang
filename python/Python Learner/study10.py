s2 = ['need']
s1 = input()
for i in s2:
    if i in s1:
        s1 = s1.replace(i, '*')
print(s1)
s = 'boys are good,boys like VS'
s1 = ''
n = 0
for i in s:
    if i.isalnum() or i == ' ':
        s1 = s1 + i
    else:
        i = ' '
        s1 = s1 + i
print(s1)
s2 = s1.split()
s3 = []
for j in s2:
    if s2.count(j) >= 2:
        if j not in s3:
            s3.append(j)
print('两次以上热度词', s3)

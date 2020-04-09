str1 = '春天在哪里，在春风里'
str2 = '春天在那里，春意盎然的地方'
num = 0
j = 0
for i in str2:
    if i.isalnum():
        j += 1
for i in str1:
    if i.isalnum() and i in str2:
        num = num + 1
rate = num / j
print('重复率为{:.1%}'.format(rate))
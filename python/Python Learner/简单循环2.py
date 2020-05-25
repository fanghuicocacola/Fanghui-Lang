str0 = ''
str1 = str(input())
for i in str1:
    str0 = str0 + i
    if i == '，':
        break
print(str0)
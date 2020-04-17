str1 = 'boys are good,boys like VS'
str2 = str1.split()
n = 0
for i in str2:
    if 'boys' in i:
        n += 1
print(n)

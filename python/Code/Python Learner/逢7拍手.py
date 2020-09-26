# 方法一
j = 0
for number in range(1, 100):
    if str(number).find('7') == 0 or number % 7 == 0 or str(number).endswith('7'):
        j += 1
print(j)
# 方法二
j = 0
for number in range(1, 100):
    if '7' in str(number) or number % 7 == 0:
        j += 1
        continue
print(j)
for i in range(1, 100):
    if str(i).find("7") != -1 or i % 7 == 0:
        print(i, end='、')



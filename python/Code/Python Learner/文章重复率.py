import codecs
k = 0
num = 0
s1 = codecs.open('1.txt', 'r', encoding='utf-8')
str1 = s1.read()
s2 = codecs.open('2.txt', 'r', encoding='utf-8')
str2 = s2.read()
for i in str2:
    if i.isalnum():
        k += 1
for i in str1:
    if i.isalnum() and i in str2:
        num = num + 1
rate = num / k
print('重复率为{:.1%}'.format(rate))
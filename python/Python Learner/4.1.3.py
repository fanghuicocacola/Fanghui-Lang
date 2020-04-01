import codecs
f = codecs.open('a.txt', 'r', encoding='utf-8')
str1 = f.read()
n = 0
for i in range(1, len(str1), 1):
    s = str1[i]
    if s == '？' or s == '。' or s == '！':
        n += 1
print(n)

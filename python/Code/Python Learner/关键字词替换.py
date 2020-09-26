# 方法一
import codecs
import re
s1 = codecs.open('a.txt', 'r', encoding='utf-8')
str1 = s1.read()
rep = str1.replace("美国", "$").replace("杀", "$").replace("枪支", "$")
print(rep)

# 方法二
s2 = codecs.open('a.txt', 'r', encoding='utf-8')
str2 = s2.read()
str2 = re.compile('(美国|杀|枪支)').sub('$',str2)
print(str2)


import codecs
a = int(input())
f = codecs.open('a.txt', 'w')
a1 = (a//1000) % 10
a2 = (a//100) % 10
a3 = (a//10) % 10
a4 = a % 10
a = a1+a2+a3+a4
b = a4*1000+a3*100+a2*10+a1
a = a+b
print(a)

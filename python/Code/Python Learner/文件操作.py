f = open("邮编.txt", 'r', encoding='utf-8')
cont = f.readlines()
L = []
for i in cont:
    i = i.strip()
    s = i.split(',')
    disc = {}
    disc.update(邮编=s[0], 地区=s[1])
    L.append(disc)
find = input('输入地区：')
for i in L:
    if find == i['地区']:
        print('邮政编码是'+i['邮编'])
f.close()

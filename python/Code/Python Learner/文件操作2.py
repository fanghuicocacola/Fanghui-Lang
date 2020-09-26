f = open("购物单.txt", 'r', encoding='utf-8')
cont1 = f.readlines()
L = []
for i in cont1:
    i = i.strip()
    s = i.split(' ')
    disc = {}
    disc.update(种类=s[0], 单价=float(s[1]), 数量=int(s[2]))
    L.append(disc)
while 1:
    find = input('物品名：')
    for i in L:
        if find == i['种类']:
            print('需付款'+str(i['单价']*i['数量'])+'￥')
f.close()

import random
room = [[], [], []]
th = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
random.shuffle(th)
print(th)
k = 0
for i in room:
    a = th[k:k+3]
    i.append(a)
    k = k + 3
n = 1
print(room)
for j in room:
    print(f'办公室{n}的老师：', end='')
    for name in j:
        print(name, end='')
    n = n + 1
    print()

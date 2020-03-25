i = 0
for i in range(100, 1000, 1):
    a1 = i % 10
    a2 = i // 10 % 10
    a3 = i // 100
    a = a1**3 + a2**3 + a3**3
    if i == a:
        print('第一个水仙花数', a)
        break

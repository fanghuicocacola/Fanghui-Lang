s = 0
n = 1
for i in range(1, 11, 1):
    for j in range(1, i, 1):
        n = n*j
    s = s + 1/n
    n = 1
print(s)
i = 0
a = i
for i in range(1, 100, 1):
    if i % 2 == 0 and i % 3 == 0:
        a = a + i
print(a)


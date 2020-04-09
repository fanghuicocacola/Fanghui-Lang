
def f(n):
    j, k = 1, 2
    for i in range(n + 1):
        c = j
        j = k
        k = c*k
    return j
print(1, end=' ')
for i in range(1, 10, 1):
    print(f(i), end=' ')
x = float(input())
s = 0
n = 0
j = 1
for i in range(2, 100000, 2):
    n = (x**i)/i
    s += -n*j
    j = -j
    if n <= 10**-5:
        break;
print(s)
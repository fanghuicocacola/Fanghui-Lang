
d = {}
n = int(input())
a = []
a = input().split()
m = []
for i in range(1, n + 1):
    d[a[i-1]] = i
q = int(input())
for i in range(1, q+1):
    b = input()
    m.append(b)

for i in range(1,q+1):
    if m[i-1] in d.keys():
        print(d[m[i-1]])
    else:
        print(0)

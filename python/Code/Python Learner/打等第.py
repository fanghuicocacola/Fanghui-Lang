s = ['tony',93], ['david', 58],['rose', 74]
for i in s:
    if i[1] < 60:
        i.append('C')
    elif 85 > i[1] >= 60:
        i.append('B')
    elif i[1] >= 85:
        i.append('A')
print(s)
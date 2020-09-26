s1 = [1, 2, 7, 4, 5]
place = s1.index(max(s1))
s1.insert(place, 6)
s1.pop(place+2)
print(s1)

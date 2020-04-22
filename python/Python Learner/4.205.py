str1 = int(input('输入一个数,'))
s = [3, 5, 8, 12, 15]
for i in range(len(s)):
    if str1 <= 3:
        s.insert(0, str1)
        break
    elif s[i - 1] <= str1 <= s[i]:
        s[i - 1] = str1
        break
    elif str1 >= 15:
        s.append(str1)
        break
print(s)
a = sorted(s, reverse=True)
print(a)

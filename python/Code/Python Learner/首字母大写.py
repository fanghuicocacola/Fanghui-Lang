s = 'you!me?he.'
result = ''
for i in range(len(s)):
    if i == 0:
        result += s[0].upper()
    elif s[i-1] == '.' or s[i-1] == '!' or s[i-1] == '?':
        result += s[i].upper()
    else:
        result += s[i]
print(result)

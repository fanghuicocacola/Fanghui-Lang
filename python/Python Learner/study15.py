s = []
while True:
    n = int(input())
    if n == 1:
        s1 = input('输入好友名，添加：')
        s.append(s1)
    if n == 2:
        s1 = input('输入好友名，删除：')
        for i in s:
            if i == s1:
                loc = s.index(i)
                s.pop(loc)
    if n == 3:
        s2 = input('输入学生名字:')
        s3 = input('输入备注：')
        for i in range(len(s), 1, 1):
            if s[i-1] == s2:
                s[i-1] = s2 + s3
    if n == 4:
        for i in s:
            print(i)
    if n == 5:
        break


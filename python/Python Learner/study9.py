import time
s1 = ['房辉', '男', '网工191', '21']
for i in s1:
    print(i)
    time.sleep(0.2)
for i in range(len(s1), 0, -1):
    print(s1[i-1])
    time.sleep(0.2)
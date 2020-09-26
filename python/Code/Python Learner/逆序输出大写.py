import time
str1 = str(input())
for i in range(1, len(str1)+1, 1):
    print(str1[-i].upper(), end='')
    time.sleep(0.2)

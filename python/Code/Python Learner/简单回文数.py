for a in range(1000, 9999, 1):
    bw = a//1000
    sw = (a % 1000)//10
    jw = (a % 100)//10
    gw = (a % 10)
    if bw == gw and sw == jw:
        print(a)

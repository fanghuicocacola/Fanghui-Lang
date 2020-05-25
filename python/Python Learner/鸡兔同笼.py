for a in range(1,45):
    for b in range(1,26):
        if a + b == 44 and 2*a + 4*b == 100:
            print(f'鸡{a},兔{b}')
for a in range(1,34):
    for b in range(1,50):
        for c in range(1,101):
            if a + b + c == 100 and 3*a + 2*b + c/2 == 100:
                print(f'大{a},中{b},小{c}')
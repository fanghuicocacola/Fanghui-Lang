import random
s1 = random.choice(['石头', '剪刀', '布'])
s2 = str(input('出石头剪刀布：'))
if s1 == '石头':
    if s2 == '布':
        print("win")
    elif s2 == s1:
        print('平')
    elif s2 == '剪刀':
        print('lost')
elif s1 == '剪刀':
    if s2 == '布':
        print("lost")
    elif s2 == s1:
        print('平局')
    elif s2 == '石头':
        print('win')
elif s1 == '布':
    if s2 == '石头':
        print("lost")
    elif s2 == s1:
        print('平局')
    elif s2 == '剪刀':
        print('win')


print('电脑', s1)

money = int(input('请输入营业额：'))
n = str(input('非事业单位输0，不是无所谓:'))
if n == '0':
    if money >= 10000:
        M = money*0.2
    elif 500 <= money <= 999:
        M = money*0.1
    elif 100 <= money <= 499:
        M = money*0.05
    else:
        M = money*0.03
else:
    if money >= 10000:
        M = money*0.1
    elif 500 <= money <= 999:
        M = money*0.05
    elif 100 <= money <= 499:
        M = money*0.03
    else:
        M = money*0.01
print("纳税金额", M)


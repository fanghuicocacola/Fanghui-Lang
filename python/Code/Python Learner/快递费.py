weight = float(input("请输入重量："))
place = str(input("请输入地区编号:"))
if place == '01':
    if weight <= 2:
        print("快递13元")
    if weight > 2:
        s = (weight-2)*3 + 13
        print("快递费", s)
elif place == '02':
    if weight <= 2:
        print("快递12元")
    if weight > 2:
        s = (weight-2)*2 + 12
        print("快递费", s)
elif place == '02':
    if weight <= 2:
        print("快递14元")
    if weight > 2:
        s = (weight - 2) * 4 + 14
        print("快递费", s)

import xlrd
import xlwt
import matplotlib.pyplot as plt
import numpy as np

# 读取
temp = xlrd.open_workbook('a.xlsx')
table = temp.sheets()[0]
now = table.nrows
nol = table.ncols
# 写入
wb = xlwt.Workbook()
ws = wb.add_sheet('sheet1')
dict1 = {}
list1 = []
list2 = []
gks1 = [0, 0, 0, 0]
gks2 = {'英语': 0, '高数': 0, '大学物理': 0}
level = {'优秀': 0, '良好': 0, '及格': 0, '不及格': 0}


def create(x, y):
    title = table.cell_value(0, y)
    value = table.cell_value(x, y)
    dict1[title] = value


for i in range(1, now):
    for j in range(0, nol):
        create(i, j)
# 如果给列表添加的是dict1，列表拷贝的只是字典的地址，递归结束以后列表只有最后一个学生的成绩
    list1.append(dict1.copy())
for i in range(0, now-1, 1):
    # 统计学生挂科数并添加键值对到字典dict1
    gk1 = 0
    for k, v in list1[i].items():
        if k != '姓名':
            if v < 60:
                gk1 += 1
    list1[i].update(挂科=gk1)
    if list1[i]['挂科'] == 1:
        gks1[1] += 1
    elif list1[i]['挂科'] == 2:
        gks1[2] += 1
    elif list1[i]['挂科'] == 3:
        gks1[3] += 1
    else:
        gks1[0] += 1
    # 统计学科挂科数
    gk2 = 0
    for k, v in list1[i].items():
        if k == '英语' and v < 60:
            gks2['英语'] += 1
        if k == '高数' and v < 60:
            gks2['高数'] += 1
        if k == '大学物理' and v < 60:
            gks2['大学物理'] += 1
# 统计学生学业等第
for t in range(0, now-1, 1):
    list1[t].update(总分=list1[t]['英语']+list1[t]['高数']+list1[t]['大学物理'])
    if '挂科' in list1[t]:
        if list1[t]['总分'] > 250 and list1[t]['挂科'] == 0:
            level['优秀'] += 1
        elif list1[t]['总分'] > 220 and list1[t]['挂科'] <= 1:
            level['良好'] += 1
        elif list1[t]['总分'] > 180 and list1[t]['挂科'] <= 2:
            level['及格'] += 1
        else:
            level['不及格'] += 1
# 写入学生成绩,先写入第一行信息，在依次输入剩下信息
a = 0
for k, v in list1[0].items():
    ws.write(0, a, k)
    ws.write(1, a, v)
    a += 1
a = 2
for i in range(1, now-1, 1):
    for k, v in list1[i].items():
        ws.write(a, i, v)
        a += 1


wb.save('a2.xls')
print(list1)
print(gks1)
print(gks2)
print(level)
print()
















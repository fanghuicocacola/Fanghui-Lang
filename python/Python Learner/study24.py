import xlrd
import xlwt
import matplotlib.pyplot as plt
import numpy as np
# 正常显示中文
plt.rcParams['font.sans-serif'] = ['SimHei']
# 读取
temp = xlrd.open_workbook('a.xlsx')
table = temp.sheets()[0]
now = table.nrows
nol = table.ncols
# 写入（如果利用xlutils可以实现写入到已有文件）
wb = xlwt.Workbook()
ws = wb.add_sheet('sheet1')
dict1 = {}
list1 = []
list2 = []
list3 = []
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
for i in range(2,now,1):
    a = 0
    for k in list1[i-1].items():
        ws.write(i, a, k[1])
        a += 1
wb.save('a2.xls')
# 成绩分布柱状图
plt.figure()
name_list = ['优秀', '良好', '及格', '不及格']
num_list = [level['优秀'], level['良好'], level['及格'], level['不及格']]
plt.xlabel('成绩区间')
plt.ylabel('人数')
plt.title('等第图')
total_width = 1
width = total_width/2
plt.bar(range(len(num_list)), num_list, color='rgb', tick_label=name_list)
for xx, yy in zip(range(len(num_list)),num_list):
    plt.text(xx, yy+0.1, str(yy), ha='center')
plt.show()
# 并列显示任意两位学生成绩对比图
plt.figure()
name_list2 = ['英语', '高数', '大学物理']
stu1 = str(input('请输入学生姓名'))
stu2 = str(input('请输入学生姓名'))
for i in range(0, now-1, 1):
    if list1[i]['姓名'] == stu1:
        for j in range(0, now - 1, 1):
            if list1[j]['姓名'] == stu2:
                list2 = [list1[j]['英语']] + [list1[j]['高数']] + [list1[j]['大学物理']]
                list3 = [list1[i]['英语']] + [list1[i]['高数']] + [list1[i]['大学物理']]
x = list(range(len(name_list2)))
plt.bar(x, list2, width=0.3, label=stu2, fc='y')
for i in range(len(x)):
    x[i] = x[i] + 0.2
    # 这里name_list2，写成了name_list,找了两小时的bug
plt.bar(x, list3, width=0.3, label=stu1, tick_label=name_list2, fc='r')
plt.ylabel('分数')
plt.title('对比图')
plt.legend()
plt.show()
print('学生成绩列表', list1)
print('挂科数目统计', gks1)
print('学科挂科情况', gks2)
print('等第', level)

















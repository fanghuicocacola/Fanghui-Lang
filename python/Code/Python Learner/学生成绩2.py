import xlrd
import xlwt
import matplotlib.pyplot as plt
import tkinter
import tkinter.messagebox
from tkinter import *
import numpy as np
s=xlrd.open_workbook('a.xlsx')
sh=s.sheets()[0]
f = xlwt.Workbook(encoding='utf-8')
hh = f.add_sheet('成绩',cell_overwrite_ok=True)
Sub=['英语','高等数学','大学物理']
Level=['优秀','良好','合格','挂科']
T=['姓名','英语','高等数学','大学物理','挂科情况']
Z=['不挂科','挂一科','挂两科','挂三科']
bjg=[0,0,0]              #不及格人数
gkrs=[0,0,0,0]         #挂科人数
dj=[0,0,0,0]          #成绩等级
gkxs=[]                 #挂科学生
yxxs,lhxs,hexs,bjgxs=['全科优秀学生为：'],['全科良好学生为：'],['全科合格学生为：'],['不及格学生为：']
p,o,q=0,0,0        #关于全科等级的整型变量
n,yx,lh,jg,gk=0,0,0,0,0         #关于成绩等级的整型变量
root =tkinter.Tk()
root.title('请输入你的操作')
#root.withdraw()
l1=Label(root,text='请在长条框输入',anchor='n',bg='orange',font=('楷体',20),fg='red',justify='left')
l1.pack(side=LEFT)
root.geometry('600x400')
llll='''
1.查看学生成绩等级
2.查看学生学科不及格人数
3.查看学生挂科人数
4.查看挂科学生
5.查看不同等级学生
6.查看柱状图表 
7.写入到excle 
8.查看饼状图
提示：关闭对话框，显示项目'''
Label(root,text=llll,font=('楷体',20),anchor='w',justify='left',bg='pink').pack()
E1=Entry(root,bd=20,font=('楷体',20))
E1.pack(side=RIGHT)
def XZ():     #成绩等级
    p,n=0,0
    global yx, lh, jg, gk
    global S
    for j in range(1,4):
        p=p+S[j]
        if S[j]>=60 :
            n=n+1
        if j==3:
            if n == 3 and p >= 250 :
                yxxs.append(S[0])
                yx=yx+1
            elif  n > 1  and  p >= 220 :
                lhxs.append(S[0])
                lh=lh+1
            elif  n>0 and p > 180 :
                hexs.append(S[0])
                jg=jg+1
            else:
                bjgxs.append(S[0])
                gk=gk+1
def GK():     #添加挂科
    n=0
    for i in range(1,4):
        if S[i]<60:
            if '挂科' not in S :
                S.append('挂科')
                gkxs.append(S[0])
        elif S[i] >= 60:
            n=n+1
            if n==3 :
                S.append('不挂科')
def XKBJG():      #统计学科不及格人数
    for j in range(1,4) :
        if S[j]<60 :
            bjg[j-1]=bjg[j-1]+1
def BGK():#统计挂科门数
    n=0
    for i in range(1,4):
        if S[i]>=60:
            n=n+1
        if i==3:
            if n==3:
                gkrs[0]=gkrs[0]+1
            elif n==2:
                gkrs[1]=gkrs[1]+1
            elif n==1:
                gkrs[2]=gkrs[2]+1
            else:
                gkrs[3]=gkrs[3]+1
def WR():        #写入excel
    for j in range(0, 5):
        hh.write(i, j, S[j])
    f.save('学生成绩.xls')
for p in range(0,5):
    hh.write(0,p,T[p])
for i in range(1,sh.nrows):#函数循环体
    S = sh.row_values(i)
    XZ()
    GK()
    XKBJG()
    BGK()
    WR()
    print(S)
dj[0] = dj[0] + yx
dj[1] = dj[1] + lh
dj[2] = dj[2] + jg
dj[3] = dj[3] + gk
def HT():     #插入柱状图
    plt.rcParams['font.sans-serif']='Kaiti'
    plt.title('网工191  徐友为  2702190124')
    plt.plot(Sub, bjg)
    plt.bar(Sub,bjg)
    plt.text(0.8,20,'挂科学科')
    plt.bar(Level,dj)
    plt.ylabel('人数')
    plt.text(4,45,'成绩等级')
    plt.bar(Z,gkrs)
    plt.text(8,36,'挂科科数')
    plt.legend(['挂科学科','成绩等级','挂科课数'])
    for x,y in zip(Sub+Level+Z,bjg+dj+gkrs):
        plt.text(x,y+0.5,'%.f'%y,ha='center',va='bottom',fontsize=10.5)
    plt.show()
def QU():    #插入饼状图
    plt.rcParams['font.sans-serif']='Kaiti'
    explode=[0,0.2,0.08]
    explode1 = [0, 0.1, 0.08,0.04]
    fig1=plt.subplot(221)
    plt.title(u'学科不及格人数',fontsize=20)
    plt.pie(labels=Sub,x=bjg,autopct='%.0f%%',explode=explode,shadow=True)
    fig2=plt.subplot(212)
    plt.title(u'学科成绩等级',fontsize=20)
    plt.pie(labels=Level, x=dj, autopct='%.0f%%', explode=explode1, shadow=True)
    fig3=plt.subplot(222)
    plt.title(u'挂科科数',fontsize=20)
    plt.pie(labels=Z,x=gkrs,explode=explode1,shadow=True)
    plt.show()
def HQWB():      #从提示框输入
    var=E1.get()
    if int(var) == 1:
            XZ()
            print()
            print('不同成绩等级人数为：',dj)
    elif int(var) == 2:
            XKBJG()
            print('不同学科不及格人数为：',bjg)
    elif int(var) == 3:
            XZ()
            print('不同挂科情况人数为：',gkrs)
    elif int(var) == 4:
            BGK()
            print('挂科学生为：{}'.format(gkxs))
    elif int(var) == 5:
            print(yxxs, lhxs, hexs, bjgxs, sep='\n')
    elif int(var) == 6:
            HT()
    elif int(var) == 7:
            WR()
            print()
            print('excel写入成功')
    elif int(var) == 8:
            QU()
    return var
Button(root,text='确认',command=HQWB).pack()
root.mainloop()

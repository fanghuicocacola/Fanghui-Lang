str='The boys and girls. Girls are good. Boys are kind. Girls and boys  ...'
s1=''
for i in str:      #for语句的功能是去除str字符串中除空格外的所有字符，并保存到s1中
    if i.isalnum() or i==' ':
        s1=s1+i
    else:
        s1=s1+' '
s1=s1.lower()
s2=s1.split()  #将s1字符串按照空格分割成字符列表s2
s3=[]          #出现3次以上的热度单词列表
print(s2)
for j in s2:
    if s2.count(j) >= 3:    #判断s2中某单词是否出现3次或以上
        if j not in s3:  #判断是否重复存放热度词
            s3.append(j)

print(s3)

d = {'姓名':'张三','数学':56,'英语':48,'物理':73}
m=[]
for k,v in d.items():  #访问字典中的键和值
    if k!='姓名':
        if v<60:
           m.append(k)   #将要删除的键加入列表中
print(m)
for i in m:
    d.pop(i)  # 根据键删除对应元素
print(d)
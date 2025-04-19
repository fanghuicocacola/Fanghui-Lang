//1.	显示功能菜单，当用户输入不同功能代码时执行不同的功能。#
//2.	输入若干个学生的信息，比如5个学生。每个学生信息至少包括学号、姓名、3门课的成绩（语文、数学、外语）。#
//3.	显示这个学生的信息。#
//4.	查询最大年龄的学生信息.#
//5.	求每门课的平均成绩#
//6.	求每位学生的平均成绩#
//7.	求总分最高的同学信息#
//8.	求总分最低的同学信息#
//9.	扩展功能：
//（1）	在功能2的基础上把所有学生信息都保存到文件中。#
//（2）	从文件中读取信息#
//（3）	对学生总分进行降序
//（4）	对学生总分进行升序
//（5）	学生结构体多添加几个字段，例如性别、年龄等。#
//（6）	查询最小年龄的同学#
//（7）	计算所有同学的平均年龄

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define STU_NUM  5  //学生个数
//学生信息
struct Student {
    char num[20];
    char name[20];
    int age;
    float chinese;
    float maths;
    float english;
    float total_stu;
    float total_ch;
    float total_ma;
    float total_en;
    float average_stu;

};

void inputStudent(struct Student aa[], int n);
void displayStudent(struct Student aa[], int n);
struct Student getAgeMax(struct Student aa[], int n);
void  Average_stu(struct Student aa[],int n);
void Total_all(struct Student aa[],int n);
void compareTotal_stu(struct Student aa[],int n);
void writefile(struct Student aa[], int n);
void readfile();
struct Student getAgeMin(struct Student aa[], int n);
void average_age(struct Student aa[],int n);
void sort_stuup(struct Student aa[],int n);
void sort_studown(struct Student aa[],int n);

char menu();

int main(void)
{

    struct Student stu[STU_NUM];
    struct Student s1;
    struct Student s2;

    printf("\n 学生成绩管理系统\n");

    char ch;
    while (1)
     //设置一个死循环，可以一直给它执行指令
    {
        ch = menu();//显示菜单
        readfile();
        writefile(stu,STU_NUM);
        switch(ch)
        {
        case '1':
            //输入学生信息
            inputStudent(stu,STU_NUM);
            break;
        case '2':
            //输出学生信息
            displayStudent(stu,STU_NUM);
            break;
        case '3':
            //查询最大年龄者
            s1 = getAgeMax(stu,STU_NUM);
            printf("最大年龄学生的信息如下：\n");
            printf("学号=%s,姓名=%s,年龄=%d\n",s1.num,s1.name,s1.age);
            break;
        case'4':
            //学生各科平均成绩
            Average_stu(stu,STU_NUM);
            break;
        case'5':
            //每门课的平均成绩
            Total_all(stu,STU_NUM);
            break;
        case'6':
            //总分最高与最低
            compareTotal_stu(stu,STU_NUM);
            break;
        case'7':
            //查询最小年龄者
            s2=getAgeMin(stu,STU_NUM);
            printf("最小年龄学生的信息如下：\n");
            printf("学号=%s,姓名=%s,年龄=%d\n",s2.num,s2.name,s2.age);
            break;
        case'8':
            //计算平均年龄
            average_age(stu,STU_NUM);
            break;
        case'a':
            //学生成绩升序
            sort_stuup(stu,STU_NUM);
            break;
        case'b':
            //学生成绩降序
            sort_studown(stu,STU_NUM);
            break;
        case '0':
            return 0;

        }



    }


    return 0;
}

//输入学生信息
void inputStudent(struct Student aa[], int n)
{
    int i;
    printf("请依次输入5个学生的学号、姓名、年龄、语文、数学、英语");
    for (i=0;i<n;i++ )
    {
        scanf("%s %s %d %f %f %f",
              aa[i].num,aa[i].name,&aa[i].age,&aa[i].chinese,&aa[i].maths,&aa[i].english);
    }
    return;
}

//输出学生信息
void displayStudent(struct Student aa[], int n)
{
    int i;

    for (i=0;i<n;i++)
    {
        printf("num=%s,name=%s,age=%d,chinese=%f,maths=%f,english=%f\n"
               ,aa[i].num,aa[i].name,aa[i].age,aa[i].chinese,aa[i].maths,aa[i].english);
    }
}
//查询学生中的最大年龄
struct Student getAgeMax(struct Student aa[], int n)
{

    int i;
    int age,pos;
    age = 0;
    for (i=0;i<n;i++)
    {
        if (age<aa[i].age)
        {
            age = aa[i].age;
            pos = i;
        }
    }
    return aa[pos];
}
//计算学生平均成绩
void  Average_stu(struct Student aa[], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        aa[i].total_stu=aa[i].chinese+aa[i].maths+aa[i].english;
        aa[i].average_stu=aa[i].total_stu/3.0;

        printf("学生%s的平均成绩为%f",aa[i].name,aa[i].average_stu);
    }
    return ;
}
//计算各科平均分
void Total_all(struct Student aa[], int n)
{
    int i;
    float total_ch=0,total_ma=0,total_en=0;
    float average_ch,average_ma,average_en;
    for (i=0;i<n;i++)
    {
        total_ch=aa[i].chinese+total_ch;
    }
    for (i=0;i<n;i++)
    {
        total_ma=aa[i].maths+total_ma;
    }
    for (i=0;i<n;i++)
    {
        total_en=aa[i].english+total_en;
    }
    average_ch=total_ch/5.0;
    average_ma=total_ma/5.0;
    average_en=total_en/5.0;
    printf("语文平均成绩是%f,数学平均成绩是%f，英语平均成绩是%f",average_ch,average_ma,average_en);
    return ;
}
//比较总分高低
void compareTotal_stu(struct Student aa[],int n)
{
    int i;
    int pos1,pos2;
    int max,min;
    max=300;
    min=0;

    for (i=0;i<n;i++)
    {
        aa[i].total_stu=aa[i].chinese+aa[i].maths+aa[i].english;
        if(aa[i].total_stu>min)//计入最小值
        {
            min=aa[i].total_stu;
            pos1=i;
        }
        if(aa[i].total_stu<max)//计入最大值
        {
            max=aa[i].total_stu;
            pos2=i;
        }

    }
    printf("总分最高的是%s，总分是%f；总分最低的是%s，总分是%f",
           aa[pos1].name,aa[pos1].total_stu,aa[pos2].name,aa[pos2].total_stu);

    return ;
}
//写文件
void writefile(struct Student aa[], int n)
{
    FILE * fp;						// 声明文件指针
    fp = fopen("student.txt", "w");	// "w"只写方式打开一个文件，文件不存在则创建
    if (fp == NULL)					// 打开文件失败，打印出错信息 .  NULL:指针的空值
    {
        printf("文件打开失败\n");
        exit(0);					// 退出程序
    }

    int i;
    for (i=0;i<2;i++)
    {
        fwrite(  &aa[i],sizeof(struct Student), 1,fp  );
    }

    fclose(fp);						// 关闭文件，释放资源
    // 将数据内容写入到文件中,每次写的字节长度单位是sizeof(struct Student)， 每次写 1 个单位。

    printf("写文件成功！");

    return fp;
}

//读文件
void readfile()
{

    FILE *fp;//声明一个文件指针
    struct Student stu;
    fp = fopen("./student.txt", "r");	// "r"只读方式打开一个文件，文件不存在则创建

    while (!  feof(fp)  )				// 判断文件指针是否已指向文件的末尾。eof: end of file

    {                                   //当文件指针fp指向文件尾部时，函数feof()返回值真
        memset(&stu, 0, sizeof(struct Student));// 初始化数据数组
        fread(&stu, sizeof(struct Student) , 1, fp); // 将文件fp中的数据读取到变量stu中
        printf("%s,%d\n", stu.name,stu.age);		// 打印stu中的数据
    }
    fclose(fp);
    return ;
}
//查找学生中的最小年龄
struct Student getAgeMin(struct Student aa[], int n)
{

    int i;
    int age,pos;
    age = 0;
    for (i=0;i<n;i++)
    {
        if (age>aa[i].age)
        {
            age = aa[i].age;
            pos = i;
        }
    }
    return aa[pos];
}
//计算平均年龄
void  average_age(struct Student aa[],int n)
{
    int i;
    float ave_age;
    int total_age;
    total_age=0;
    for (i=0;i<n;i++)
    {
        total_age=aa[i].age +total_age;
    }
    ave_age=total_age*1.0/5.0;
    printf("平均年龄为%f",ave_age);
    return ;
}
//对学生总分进行排序升序
void sort_stuup(struct Student aa[], int n)
{
    int i;
    for (i = 0; i <n; i += 1)
    {
        aa[i].total_stu=aa[i].chinese+aa[i].maths+aa[i].maths;
        int key = aa[i].total_stu;
        int j = i-1;
        for (; j >=0 && aa[j].total_stu >key; j -= 1)
        {
            aa[j+1].total_stu = aa[j].total_stu;
        }
        aa[j+1].total_stu = key;
    }
    for (i = 0; i < n; i += 1)
    {
        printf("%f  ,",aa[i].total_stu);
    }

    return ;
}
//降序
void sort_studown(struct Student aa[], int n)
{
    int i;
    for (i = 0; i <n; i += 1)
    {
        aa[i].total_stu=aa[i].chinese+aa[i].maths+aa[i].maths;
        int key = aa[i].total_stu;
        int j = i-1;
        for (; j >=0 && aa[j].total_stu <key; j -= 1)
        {
            aa[j+1].total_stu = aa[j].total_stu;
        }
        aa[j+1].total_stu = key;
    }
    for (i = 0; i < n; i += 1)
    {
        printf("%f  ,",aa[i].total_stu);
    }

    return ;
}


char menu()//菜单
{
    char ch;
    printf(" 请选择功能：\n");
    printf("1.输入学生信息\n");
    printf("2.显示学生信息\n");
    printf("3.显示最大年龄\n");
    printf("4.显示每门课成绩的平均值\n");
    printf("5.每门课的平均成绩\n");
    printf("6.总分最高与最低\n");
    printf("7.显示最小年龄\n");
    printf("8.平均年龄\n");
    printf("a.升序\n");
    printf("b.降序\n");
    printf("0:退出系统\n");
    scanf(" %c",&ch); //注意%c 前面有一个空格
    return ch;
}


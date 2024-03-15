//1.	��ʾ���ܲ˵������û����벻ͬ���ܴ���ʱִ�в�ͬ�Ĺ��ܡ�#
//2.	�������ɸ�ѧ������Ϣ������5��ѧ����ÿ��ѧ����Ϣ���ٰ���ѧ�š�������3�ſεĳɼ������ġ���ѧ�������#
//3.	��ʾ���ѧ������Ϣ��#
//4.	��ѯ��������ѧ����Ϣ.#
//5.	��ÿ�ſε�ƽ���ɼ�#
//6.	��ÿλѧ����ƽ���ɼ�#
//7.	���ܷ���ߵ�ͬѧ��Ϣ#
//8.	���ܷ���͵�ͬѧ��Ϣ#
//9.	��չ���ܣ�
//��1��	�ڹ���2�Ļ����ϰ�����ѧ����Ϣ�����浽�ļ��С�#
//��2��	���ļ��ж�ȡ��Ϣ#
//��3��	��ѧ���ֽܷ��н���
//��4��	��ѧ���ֽܷ�������
//��5��	ѧ���ṹ�����Ӽ����ֶΣ������Ա�����ȡ�#
//��6��	��ѯ��С�����ͬѧ#
//��7��	��������ͬѧ��ƽ������

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define STU_NUM  5  //ѧ������
//ѧ����Ϣ
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

    printf("\n ѧ���ɼ�����ϵͳ\n");

    char ch;
    while (1)
     //����һ����ѭ��������һֱ����ִ��ָ��
    {
        ch = menu();//��ʾ�˵�
        readfile();
        writefile(stu,STU_NUM);
        switch(ch)
        {
        case '1':
            //����ѧ����Ϣ
            inputStudent(stu,STU_NUM);
            break;
        case '2':
            //���ѧ����Ϣ
            displayStudent(stu,STU_NUM);
            break;
        case '3':
            //��ѯ���������
            s1 = getAgeMax(stu,STU_NUM);
            printf("�������ѧ������Ϣ���£�\n");
            printf("ѧ��=%s,����=%s,����=%d\n",s1.num,s1.name,s1.age);
            break;
        case'4':
            //ѧ������ƽ���ɼ�
            Average_stu(stu,STU_NUM);
            break;
        case'5':
            //ÿ�ſε�ƽ���ɼ�
            Total_all(stu,STU_NUM);
            break;
        case'6':
            //�ܷ���������
            compareTotal_stu(stu,STU_NUM);
            break;
        case'7':
            //��ѯ��С������
            s2=getAgeMin(stu,STU_NUM);
            printf("��С����ѧ������Ϣ���£�\n");
            printf("ѧ��=%s,����=%s,����=%d\n",s2.num,s2.name,s2.age);
            break;
        case'8':
            //����ƽ������
            average_age(stu,STU_NUM);
            break;
        case'a':
            //ѧ���ɼ�����
            sort_stuup(stu,STU_NUM);
            break;
        case'b':
            //ѧ���ɼ�����
            sort_studown(stu,STU_NUM);
            break;
        case '0':
            return 0;

        }



    }


    return 0;
}

//����ѧ����Ϣ
void inputStudent(struct Student aa[], int n)
{
    int i;
    printf("����������5��ѧ����ѧ�š����������䡢���ġ���ѧ��Ӣ��");
    for (i=0;i<n;i++ )
    {
        scanf("%s %s %d %f %f %f",
              aa[i].num,aa[i].name,&aa[i].age,&aa[i].chinese,&aa[i].maths,&aa[i].english);
    }
    return;
}

//���ѧ����Ϣ
void displayStudent(struct Student aa[], int n)
{
    int i;

    for (i=0;i<n;i++)
    {
        printf("num=%s,name=%s,age=%d,chinese=%f,maths=%f,english=%f\n"
               ,aa[i].num,aa[i].name,aa[i].age,aa[i].chinese,aa[i].maths,aa[i].english);
    }
}
//��ѯѧ���е��������
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
//����ѧ��ƽ���ɼ�
void  Average_stu(struct Student aa[], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        aa[i].total_stu=aa[i].chinese+aa[i].maths+aa[i].english;
        aa[i].average_stu=aa[i].total_stu/3.0;

        printf("ѧ��%s��ƽ���ɼ�Ϊ%f",aa[i].name,aa[i].average_stu);
    }
    return ;
}
//�������ƽ����
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
    printf("����ƽ���ɼ���%f,��ѧƽ���ɼ���%f��Ӣ��ƽ���ɼ���%f",average_ch,average_ma,average_en);
    return ;
}
//�Ƚ��ָܷߵ�
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
        if(aa[i].total_stu>min)//������Сֵ
        {
            min=aa[i].total_stu;
            pos1=i;
        }
        if(aa[i].total_stu<max)//�������ֵ
        {
            max=aa[i].total_stu;
            pos2=i;
        }

    }
    printf("�ܷ���ߵ���%s���ܷ���%f���ܷ���͵���%s���ܷ���%f",
           aa[pos1].name,aa[pos1].total_stu,aa[pos2].name,aa[pos2].total_stu);

    return ;
}
//д�ļ�
void writefile(struct Student aa[], int n)
{
    FILE * fp;						// �����ļ�ָ��
    fp = fopen("student.txt", "w");	// "w"ֻд��ʽ��һ���ļ����ļ��������򴴽�
    if (fp == NULL)					// ���ļ�ʧ�ܣ���ӡ������Ϣ .  NULL:ָ��Ŀ�ֵ
    {
        printf("�ļ���ʧ��\n");
        exit(0);					// �˳�����
    }

    int i;
    for (i=0;i<2;i++)
    {
        fwrite(  &aa[i],sizeof(struct Student), 1,fp  );
    }

    fclose(fp);						// �ر��ļ����ͷ���Դ
    // ����������д�뵽�ļ���,ÿ��д���ֽڳ��ȵ�λ��sizeof(struct Student)�� ÿ��д 1 ����λ��

    printf("д�ļ��ɹ���");

    return fp;
}

//���ļ�
void readfile()
{

    FILE *fp;//����һ���ļ�ָ��
    struct Student stu;
    fp = fopen("./student.txt", "r");	// "r"ֻ����ʽ��һ���ļ����ļ��������򴴽�

    while (!  feof(fp)  )				// �ж��ļ�ָ���Ƿ���ָ���ļ���ĩβ��eof: end of file

    {                                   //���ļ�ָ��fpָ���ļ�β��ʱ������feof()����ֵ��
        memset(&stu, 0, sizeof(struct Student));// ��ʼ����������
        fread(&stu, sizeof(struct Student) , 1, fp); // ���ļ�fp�е����ݶ�ȡ������stu��
        printf("%s,%d\n", stu.name,stu.age);		// ��ӡstu�е�����
    }
    fclose(fp);
    return ;
}
//����ѧ���е���С����
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
//����ƽ������
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
    printf("ƽ������Ϊ%f",ave_age);
    return ;
}
//��ѧ���ֽܷ�����������
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
//����
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


char menu()//�˵�
{
    char ch;
    printf(" ��ѡ���ܣ�\n");
    printf("1.����ѧ����Ϣ\n");
    printf("2.��ʾѧ����Ϣ\n");
    printf("3.��ʾ�������\n");
    printf("4.��ʾÿ�ſγɼ���ƽ��ֵ\n");
    printf("5.ÿ�ſε�ƽ���ɼ�\n");
    printf("6.�ܷ���������\n");
    printf("7.��ʾ��С����\n");
    printf("8.ƽ������\n");
    printf("a.����\n");
    printf("b.����\n");
    printf("0:�˳�ϵͳ\n");
    scanf(" %c",&ch); //ע��%c ǰ����һ���ո�
    return ch;
}


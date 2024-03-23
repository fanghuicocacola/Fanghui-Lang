#include<iostream>
#include <math.h>
#include<string.h>

/*
    1）编写一个主程序，判断输入的一个大于1的正整数是否是素数，输出“是”或“不是”。
    2）编写函数，对一维数组采用冒泡法进行排序
    3）编写程序，完成Student类的构造函数、析构函数、Print()函数的定义，其中Print()函数用来输出
       姓名、学号、VC++考试成绩。
*/
int isPrime(int x)
{
    for(int i=2;i<sqrt(x);i++)
    {
        if(x%i == 0)
            return 0;
    }
    return 1;
}
void BubbleSort(int a[],int size)
{
    int temp,flag = 0;
    for(int i=0;i<size;i++)
    {
        flag = 0;
        for(int j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                flag = 1;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag == 0)
            break;
    }
}
void func1()
{
    int xx;
    std::cin>>xx;
    if(xx<=1)
    {
        std::cout<<"please enter a number > 1!"<<std::endl;
        exit(0);
    }
    if(isPrime(xx))
        std::cout<<"is prime";
    else
        std::cout<<"not prime";
}

void func2()
{
    int aa[10] = {1,3,4,66,77,12,34,0,9,10};
    BubbleSort(aa,10);
    for(int i=0;i<10;i++)
    {
        std::cout<<aa[i]<<std::endl;
    }
}

class Student
{
    private:
        char *name;
        int id;
        float scoreCPP;
    public:
        Student(const char *n,int num,float score)
        {
            name = new char(strlen(n)+1);
            strcpy(name,n);
            id = num;
            scoreCPP = score;
            std::cout<<"Construct!"<<std::endl;
        }
        void Print()
        {
            std::cout<<"Name: "<<name<<" ID: "<<id<<" socreCPP: "<<scoreCPP<<std::endl;
        }
        ~Student()
        {
            delete[] name;
            std::cout<<"Destruct!"<<std::endl;
        }
};

void func3()
{
    Student stu1("Jack",10023,98);
    stu1.Print();
}
int main()
{
    func1();
    func2();
    func3();
}
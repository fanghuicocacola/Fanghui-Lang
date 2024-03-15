// 学生成绩管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//1.	显示功能菜单，当用户输入不同功能代码时执行不同的功能。
//2.	输入若干个学生的信息，比如5个学生。每个学生信息至少包括学号、姓名、3门课的成绩（语文、数学、外语）。
//3.	显示这个学生的信息。
//4.	查询最大年龄的学生信息.
//5.	求每门课的平均成绩
//6.	求每位学生的平均成绩
//7.	求总分最高的同学信息
//8.	求总分最低的同学信息
#include <iostream>
#include <fstream>
using namespace std;
Main_menu();//主菜单
typedef struct Student
{
	char name[20];
	char num[10];
	int age;
	double score;
	Student* next;
}*SP;
fstream f1;//定义文件为可输入输出文件
SP head = NULL, rear = NULL;//头指针、尾指针
int main()
{
	return 0;
}
void Menu()//界面
{
	cout << "==============学生成绩管理系统==============" << endl;
	cout << "              1.学生信息录入                " << endl;
	system("pause");
}
void Main_menu()//主菜单
{
}

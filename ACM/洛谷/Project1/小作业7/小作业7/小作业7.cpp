// 小作业7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
void fun(double &y, double x, int n)
{
	y = x;
	while (n > 1)
	{
		y = y * x;
		n--;
	}
}
int main()
{
	double x1;
	double &y1 = x1;
	int n1;
	scanf_s("%f %d", &x1, &n1);
	fun(y1, x1, n1);
	printf("%f", y1);
}


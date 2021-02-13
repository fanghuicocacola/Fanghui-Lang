// P1223排队接水.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
using namespace std;
struct p {
	int num, t;
};
int main()
{
	int n, b = 1;
	double sum = 0;
	float tt = 0.0;
	p a[1001];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i].num = i+1;
		scanf_s("%d", &a[i].t);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++) 
		{
			if (a[j].t > a[j + 1].t)
			{
				swap(a[j].t, a[j + 1].t);
				swap(a[j].num, a[j + 1].num);
			}
		}
	}
	for (int i = 0; i < n; i++) 
	{
		b = 1;
		b = a[i].t*(n - i - 1);
		sum += b;
		printf("%d ", a[i].num);
	}
	tt = sum / n;
	printf("\n%.2f", tt);
	return 0;
}



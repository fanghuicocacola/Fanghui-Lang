// P1519阶乘数码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
 
#include <iostream>
#include <stdio.h>
int a[10001];
int main()
{
	int n,length = 0;
	int m, t, tt[11] = { 0 };
	scanf_s("%d",&t);
	for (int i = 0; i < t; i++)
	{
		length = 0;
		tt[i] = 0;
		m = 0;
		for (int j = 1; j <= 10001; j++)
			a[j] = 0;//数组清零
		a[1] = 1;
		scanf_s("%d%d", &n, &m);
		for (int j = 1; j <= n; j++)
		{
			int carry = 0, p = 0;
			while (1)
			{
				int products;
				products = a[p] * j + carry;
				a[p] = products % 10;
				carry = products / 10;
				p++;
				if (carry == 0 && a[p] == 0 && p >= length)
					break;
			}
			length = p;
		}
		for (int j = length-1; j > 0; j--)
		{
			if (a[j] == m)
			{
				tt[i]++;
			}
		}
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", tt[i]);
	}
}



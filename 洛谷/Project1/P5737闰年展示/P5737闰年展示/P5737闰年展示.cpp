// P5737闰年展示.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<iostream>
using namespace std;
int ans[1500];
int main() {
	int begin, end;
	scanf_s("%d%d", &begin, &end);
	int n = 0;
	for (int i = begin; i <= end; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) 
		{
			ans[n++] = i;
		}
	}
	printf("%d", n);
	for (int i = 0; i < n; i++) 
	{
		printf("%d ", ans[i]);
	}
	return 0;
}

// 19.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<math.h>
#include<stdio.h>
int main(void)
{
	float x0, x1, x2, x3, fx0, fx1, fx2;
	do {
		printf("please enter two numbers x1,x2:");
		scanf_s("%f,%f", &x1, &x2);
		fx1 = x1 * ((2 * x1 - 4) * x1 + 3) - 6;
		fx2 = x2 * ((2 * x2 - 4) - x2 + 3) - 6;
	} while (fx1 * fx2 > 0);
	printf("x=%6.2f\n", x0);
	return 0;

}


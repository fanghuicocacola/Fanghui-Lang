// ConsoleApplication29.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

int main() 
{
    int n, a = 0, total = 0; 
    scanf_s("%d",&n);
    while (total < n) {
        a++;
        total += a;
    }
    if (a % 2 == 1)
        printf_s("%d/%d", total - n + 1, a - (total - n));
    else
        printf_s("%d/%d", a - (total - n), total - n + 1);
}
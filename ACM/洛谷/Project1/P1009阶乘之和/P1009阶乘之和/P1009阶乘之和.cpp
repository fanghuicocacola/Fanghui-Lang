// P1009阶乘之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
int a[10000] = { 1 };// 存储阶乘结果
int b[10000] = { 0 };//存储加法结果
int length = 1;

int main()
{
    int n;
    scanf_s("%d", &n);
    for (int i = 1; i <= n; i++) {
        int p = 0;
        int carry = 0; //进位标志
        while (1)
        {
            int product = a[p] * i + carry;   //从低位到高位模拟乘法的过程 
            a[p] = product % 10;
            carry = product / 10;
            p++;
            if (a[p] == 0 && carry == 0 && p >= length) {
                break;  //多余0元素的排除——提前终止乘法运算 
            }
        }
        length = p; //length变量获取当前数值的长度
        for (int i = 0; i < length; i++) { //高精加
            b[i] += a[i];
            if (b[i] > 9) {
                b[i + 1] += b[i] / 10;
                b[i] %= 10; //进位
            }
        }
    }
    while (!b[length] && length > 0) length--; //去掉首导零
    for (int i = length; i >= 0; i--)
        std::cout << b[i];
}

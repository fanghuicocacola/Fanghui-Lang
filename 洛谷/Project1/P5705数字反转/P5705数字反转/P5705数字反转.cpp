// P5705数字反转.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include  <stdio.h>
#include<cstring>
int main()
{
    char s[6] = { };
    scanf_s("%s",&s,6);
    for (int i = strlen(s) -1; i >= 0; i--)
        printf_s("%c", s[i]);
    return 0;
}

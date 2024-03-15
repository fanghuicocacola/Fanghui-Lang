﻿#include<stdio.h>
#define a 10000

int f[1000001], g[1000001];

int main()
{
    int n;
    scanf_s("%d", &n);
    f[0]  = f[1] = g[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] =(f[i - 1] + f[i - 2] + 2 * g[i - 2])%10000;

        g[i] =(f[i - 1] + g[i - 1])%10000;
    }
    printf("%d", f[n]);
}


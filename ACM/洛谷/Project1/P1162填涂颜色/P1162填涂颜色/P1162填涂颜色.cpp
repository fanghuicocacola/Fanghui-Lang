#include <iostream>
#include <stdio.h>
int main()
{
    int a[31][31], b[31][31];
    int n, j, k, t1 = 4, t2 = 4;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf_s("%d", &a[i][j]);
            b[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        t1 = 4, t2 = 4;
        j = 0;
        k = n - 1;
        while (k > j) {
            if (t1 != 1) {
                if (b[i][j] != 1)
                    b[i][j] = 3;
                else
                {
                    t1 = 1;
                }
            }
            if (t2 != 1) {
                if (b[i][k] != 1)
                {
                    b[i][k] = 3;
                }
                else 
                {
                    t2 = 1;
                }
            }
            if (b[i][k] == 1 && b[i][j] == 1)
                break;
            j++;
            k--;
        }
    }
    for (int i = 0; i < n; i++)
    {   
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] == 0)
            {
                a[i][j] = 2;
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("%d ", a[i][j]);
            }
        }
        
    }
    return 0;
}
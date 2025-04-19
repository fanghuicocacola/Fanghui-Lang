#include <stdio.h>
void func(int(*pa)[4],int (*pb)[3],int x, int y)
{
    int i, j;
    //输出pa指向的二维数组的元素
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%d\t", pa[i][j]);
            pb[j][i] = pa[i][j]; //矩阵转置

        }
        printf("\n");
    }
    printf("\n\n");
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            printf("%d\t", pb[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i,j;
    int arr[3][4],brr[4][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    return 0;
}

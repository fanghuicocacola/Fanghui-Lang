#include<iostream>
#include<time.h>
#define Max 100

void CreatInt(int *s)
{
    int aa, i;
    srand((unsigned)time(NULL));//初始化随机数
    for (i = 0; i < Max; i++)
    {
        aa = rand() % 99 + 1;//随机数的产生调用rand()函数
        s[i] = aa;
    }

}
void insort(int s[], int n)//自定义排序函数 insort
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        s[0] = s[i];//s[0] 做监视哨 每次 比较 为其赋值
        j = i - 1;		//建立 循环变量i的副本 从右往左比较
        while (s[0] < s[j])
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = s[0];//在 确定好的位置 上插入 s[i]
    }
}
int main()
{
    int i;
    int a[Max] = { 0 };
    CreatInt(a);
    printf("\n输出随机数:  \n");
    for (i = 0; i < Max; i++)
        printf("%d ", a[i]);
    printf("\n原始顺序是： \n");
    for (i = 0; i < Max; i++)
        printf("%3d", a[i]);
    insort(a, Max);

    printf("\n插入数据排序后的顺序是：\n");
    for (i = 0; i < Max; i++)
        printf("%3d", a[i]);
    printf("\n");
    return 0;
}


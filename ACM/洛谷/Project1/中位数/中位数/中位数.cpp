#include <stdio.h>  
#include <stdlib.h>  
int px(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    float k;		          
    int i, j,n;
    int a[1001];
    int len;

    while (scanf_s("%d ", &len) != EOF) 
    {   
        for (i = 0; i < len; i++) 
            scanf_s("%d", &a[i]);
        qsort(a, len, sizeof(a[0]), px);
        if (len % 2 == 0) 
        {
            k = (a[(len / 2) - 1] + a[(len / 2)]);
            printf("%.2f\n", k / 2.00);
        }
        else {
            k = a[len / 2];
            printf("%.2f\n", k); 
        }

    }
    return 0;
}

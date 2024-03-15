#include <stdio.h>

int main(void)
{
//    int i,j;
//    i=3;
//    j=i++;
//    printf("%d",j);
    int x;

    scanf("%d",&x);
    if(x++>5)
        printf("%d",x);
    else
        printf("%d\n",x++);//++²»Ö´ÐÐ

  return 0;
}


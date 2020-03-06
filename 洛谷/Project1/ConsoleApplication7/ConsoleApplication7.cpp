#include <stdio.h>
int main(void)
{
    char a[15], c[12] = "0123456789X"; 
    gets_s(a); 
    int i, j = 0, k = 0;
    for (i = 0; i < 12; i++)
    {
        if (a[i] != '-') 
        {
            j++;
            k = k + (a[i] - '0') * j;
        }
    }
    if (c[k % 11] == a[12]) 
    {
        printf("Right");
    }
    else 
    {
        a[12] = c[k % 11];
        puts(a);
    }
    return 0;
}
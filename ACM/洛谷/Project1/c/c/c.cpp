#include <iostream>
#include <stdio.h>
int main()
{
    int n, c = 0, arr1[1000] = { 0 }, arr2[100] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr2[i]);
    for (int i = 0; i < n; i++)
    {
        int a;
        a = arr2[i];
        for(int j = 1;j <= a;j++)
            if (j % 10 == 7 || j % 100 == 7)
            {

            }
            else
            {
                c++;
            }
        printf("%d\n", c);
        c = 0;
    }
    
    
}

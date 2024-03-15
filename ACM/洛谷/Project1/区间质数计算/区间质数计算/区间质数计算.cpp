#include <stdio.h>
#include "math.h"
int main()
{
    int num, R;

    scanf_s("%d%d", &num, &R);

    int i, n = 0;
    int flag = 1;
    if (num == 2) n++;
    if (num % 2 == 0)
        num++;
    for (int k = num; k <= R; k += 2)
    {
        if (k % 2 == 0)
            continue;
        flag = 1;
        for (i = 3; i <= sqrt(k); i += 2)
        {
            if (k % i == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
            n++;
    }
    printf("%d", n);
    return 0;
}



 
 
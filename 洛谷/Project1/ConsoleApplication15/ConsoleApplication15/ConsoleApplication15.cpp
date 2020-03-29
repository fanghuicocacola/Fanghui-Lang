#include<stdio.h>

int main()
{
    int K, sum = 0, N = 0;
    scanf_s("%d", &K);
    for (int i = 1;; i++) {
        for (int j = 1; j <= i; j++) 
        {
            if (N == K) 
            {
                printf("%d", sum);
                return 0;
            }
            else
            {
                sum += i;
                N++;
            }         
        }
    }
}
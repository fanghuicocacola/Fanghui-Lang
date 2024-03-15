#include<stdio.h>

long int fact(int N)

{
    int i;
    int result = 1;
    for (i = 1; i <= N; i++)
        result = result * i;
    return result;
}
int main()
{
    int M;
    long int sum = 0;
    scanf_s("%d", &M);
    for (int i = 1; i <= M; i++)
        sum = sum + fact(i);
    printf("1!+2!+...+M!=%ld", sum);
    return 0;
}
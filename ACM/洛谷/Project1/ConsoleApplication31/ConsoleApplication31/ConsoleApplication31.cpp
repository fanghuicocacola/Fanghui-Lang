#include <stdio.h>

int total(int i)
{
    if (i == 1)
        return 1;
    return total(i - 1) * i;
}
int main()
{
    int n;
    long long int ans;
    scanf_s("%d", &n);
    printf("%d", total(n));
}



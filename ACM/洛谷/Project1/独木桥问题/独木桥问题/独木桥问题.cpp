#include <iostream>
#include<algorithm>
#include <stdio.h>
using namespace std;
int main()
{
    int n, L, p, Max = 0, Min = 0;
    scanf("%d %d", &L, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p);
        Max = max(Max, max(L - p + 1, p));
        Min = max(Min, min(L - p + 1, p));
    }
    printf("%d %d", Min, Max);
}

#include<fstream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int a[1000005], b[1000005], maxs;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    scanf_s("%d", &n);
    for (int i = 1; i <= n; i++) 
    { 
        scanf_s("%d", &a[i]);
        b[i] = a[i]; 
    }
    sort(a + 1, a + 1 + n, cmp);
    maxs = a[1];
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == maxs)
        { 
            printf("%d\n%d", i, b[i]);
            return 0; 
        }
    }
    return 0;
}


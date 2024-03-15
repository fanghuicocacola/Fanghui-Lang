#include<stdio.h>
#include<math.h>
int  n, k, x, all = 0, s = 0, a[21];
int ToPrime(int id)
{
    int i;
    if (id == 2) 
        return 1;
    for (i = 2; i <= ceil(sqrt(id)); i++)
    {
        if (id % i == 0) 
            return 0;
    }
    return 1;
}
void search(int x, int y)
{
    int i;
    if (x > k) {
        if (ToPrime(s))
            all++;
        return ;
    }
    for (i = y + 1; i <= n; i++) {
        s = s + a[i];
        search(x + 1, i);
        s = s - a[i];
    }
}

int main()
{
    int i;
    scanf_s("%d %d", &n, &k);
    for (i = 1; i <= n; i++)
        scanf_s("%d", &a[i]);
    search(1, 0);
    printf("%d", all);
}



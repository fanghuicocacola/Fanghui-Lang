#include<stdio.h>
int b[10001];
int main()
{
    int i, L, M, n = 0;
    int k;
    int a[2];
    scanf_s("%d %d", &L, &M);
    for (i = 0; i <= L; i++)
        b[i] = 0;
    for (i = 1; i <= M; i++) {
        for (k = 0; k < 2; k++)
            scanf_s("%d", &a[k]);
        for (k = 0; k <= L; k++)
            if (k >= a[0] && k <= a[1]) {
                b[k] = 1;
            }
    }
    for (i = 0; i <= L; i++)
        if (b[i] == 0) {
            n++;
        }
    printf("%d", n);
    return 0;
}
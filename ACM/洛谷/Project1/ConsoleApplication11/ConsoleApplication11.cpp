#include<stdio.h>
int a[1001];
int main() {
    int n, i ;
    a[0] = 1;
    a[1] = 1;
    scanf_s("%d", &n);
    for (i = 2; i <= n; i++) {
        if (i % 2 == 0) 
            a[i] = a[i - 1] + a[i / 2];
        else 
            a[i] = a[i - 1];
    }
    printf("%d\n", a[n]);
}
#include<stdio.h>

int f(int x) {
    int j = 1, i;
    for (i = 1; true; i++) {
        j *= 2;
        if (j > x) {
            i--;
            j = j/2;
            break;
        }
    }
    if (i == 0)
        printf("2(0)");
    if (i == 1)
        printf("2");
    if (i > 1) {
        printf("2(");
        f(i);
        printf(")");
    }
    if (x - j > 0) {
        printf("+");
        f(x - j);
    }
    if (x == 0)
        return 0;
}
int main() 
{
    int n;
    scanf_s("%d", &n);
    f(n);
    return 0;
}
#include <stdio.h>
int main()
{
    int n, x;
    int i,p=0;
    scanf_s("%d %1d", &n, &x);
    for (i = 0; i <= n; i++) {
        int a;
        a = i;
        while (a > 0) {
            int y;
            y = a % 10;
            a = a / 10;
            if (y == x) {
                p++;
            }

        }
    }
    printf("%d", p);
    return 0;
}

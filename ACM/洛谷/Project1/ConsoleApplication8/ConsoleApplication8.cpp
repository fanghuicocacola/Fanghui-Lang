#include<stdio.h>
#include<string.h>
char a[11], b[1000001];
int main()
{
    gets_s(a);
    gets_s(b);
    strcat_s(a, " ");
    strcat_s(b, " ");
    int i, j,k, s, set, n,p;
    n = 0;
    s = 0;
    for (i = 0; a[i] != '\0'; i++) {
        if (a[i] >= 'a') {
            a[i] = a[i] + 'A' - 'a';
        }
    }
    for (i = 0; b[i] != '\0'; i++) {
        if (b[i] >= 'a')
            b[i] = b[i] + 'A' - 'a';
    }
    for (i = 0; b[i] != '\0'; i++) {
        if (b[i] == ' ') {
            p = 1;
            for (j = s, k = 0; j <= i && a[k] != '\0'; j++, k++) {
                if (b[j]==a[k]) {
                    p *= 1;
                }
                else {
                    p *= 0;
                }
            }
            if (p == 1) {
                n++;
            }
            if (p == 1 && n == 1) {
                set = s;
            }
            s = i;
            s++;
        }
    }
    if (n == 0) {
        n = -1;
        printf("%d", n);
    }
    else if (n >= 1) {
        printf("%d %d", n, set);
    }
}


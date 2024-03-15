#include<stdio.h>

int main() {
    int a[4], temp;
    for (int i = 0; i < 4; i++)
        scanf_s("%d", &a[i]);
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3 - j; i++) {
            if (a[i] > a[i + 1])
            {
                temp = a[i]; a[i] = a[i + 1]; a[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 4; i++)
        printf("%d", a[i]);
    return 0;
}



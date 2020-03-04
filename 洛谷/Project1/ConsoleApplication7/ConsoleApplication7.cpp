#include<stdio.h>

int main()
{
    char a[14], c;
    int h = 0, k = 0;
    for (int i = 0; i < 11; i++)
    {
        a[i] = getchar();
        if (a[i] != '-')
        {
            k++;
            h += k * (a[i] - '0');
        }
    }
    h %= 11;
    if (h == 10) {
        c = 'X';
    }
    else
    {
        c = h + '0';
    }
    if (c == a[12]) {
        printf("right");
    }
    else
    {
        a[12] = c;
    }
    for (int i = 0; i < 12; i++) {
        printf("%c",a[i]);
    }
    return 0;
}
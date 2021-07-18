#include<stdio.h>
#include<string.h>
void str28()
{
    char s[100];
    int i, j, n, k;
    printf("input S1:\n");
    fgets(s,100,stdin);
    n=strlen(s);
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i + 1; j < n - 1; j++)
            if (s[j] != s[i])
                s[k++] = s[j];
        s[k] = '\0';
    }
    printf("new S1:\n%s", s);
}
int main()
{
    str28();
}

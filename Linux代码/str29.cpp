#include<stdio.h>
#include<string.h>
#include<ctype.h>
void str29()
{
    char s[100], s1[100]; int i, j, m = 0, pri[100], max = 0, x = 0, y = 0, n;
    fgets(s,100,stdin);
    n = strlen(s);
    for (i = 0; i < n; i++)
    {
        if (isalpha(s[i]))
        {
            pri[m] = i;
            s1[m++] = toupper(s[i]);
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j <= i && i + j < m; j++)
        {
            if (s1[i - j] != s1[i + j])break;//jishu
            if ((2 * j + 1) > max)
            {
                max = 2 * j + 1;
                x = pri[i - j];
                y = pri[i + j];
            }
        }
        for (j = 0; j <= i && i + j < m; j++)
        {
            if (s1[i - j] != s1[i + j + 1])break;//oushu
            if ((2 * j + 2) > max)
            {
                max = 2 * j + 2;
                x = pri[i - j];
                y = pri[i + j + 1];
            }
        }


    }
    for (i = x; i <= y; i++)
        printf("%c", s[i]);
}
int main()
{
    str29();
}
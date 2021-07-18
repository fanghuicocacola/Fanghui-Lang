#include <stdio.h>
#include <string.h>
#include  <math.h>
void StrToInt()
{
    char p[10];
    fgets(p,10,stdin);
    int len = strlen(p);
    int i = 0;
    int flag = 0;
    if (p[0] == '-')
    {
        i = 1;
        flag = 1;
    }
    else if (p[0] == '+')
    {
        i = 1;
        flag = 0;
    }
    int sum = 0;
    for (;i < len; ++i)
    {
        if (p[i] >= '0'&&p[i] <= '9')
        {
            sum = sum + int(p[i] - '0')*pow(10, len - i - 1);
        }
    }
    printf("%d",flag>0 ? sum*-1 : sum);
}
int main()
{

    StrToInt();
}

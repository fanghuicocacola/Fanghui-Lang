#include <stdio.h>
#include <string.h>
void str27()
{
    char str[100];
    int a[256] = { 0 };
    fgets(str,100,stdin);
    for (int i = 0; i < strlen(str); i++)
    {
        if (++a[str[i]] == 2)
        {
            if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            {
                printf("%c",str[i]);
                break;
            }
        }
    }
}
int main()
{
    str27();
}

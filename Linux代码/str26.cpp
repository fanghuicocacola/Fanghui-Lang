#include <stdio.h>
#include <string.h>
void str26()
{
    int len,i;
    char str[100];
    fgets(str,100,stdin);
    len=strlen(str);
    for(i=len-1; i>=0; i--)
        printf("%c",str[i]);
}
int main()
{
    str26();
}

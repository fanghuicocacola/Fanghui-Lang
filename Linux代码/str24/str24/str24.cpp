#include <stdio.h>
#include <string.h>

void fun() 
{
    char str[30];
    int str[30],n = 0,sum = 0;
    bool flag = true;
    fgets(str, 30, stdin);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            n = i + 1;
            while (str[n] != '+' || str[n] != '-')
            {
                n++;
            }
            sum = sum * 10 + (str[i] - 48);
        }
    }
}

int main()
{
    fun();
}


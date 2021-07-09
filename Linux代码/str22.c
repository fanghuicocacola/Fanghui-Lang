#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void str22()
{
  char str[30];
  scanf("%s",str);
  int i = 0;
  int x = 0,sum = 0;
  while(str[i] != '\0')
  {
    if(str[i]>='0'&&str[i]<='9')
    {
      x = str[i]-'0';
    }
    i++;
    sum += x;
  }
  printf("%d\n",sum);
}
int main()
{
  str22();
}

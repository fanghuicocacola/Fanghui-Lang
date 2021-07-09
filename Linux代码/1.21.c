#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void str21()
{
  char str[100],pat[10];
  scanf("%s",str);
  scanf("%s",pat);
  int n = strlen(str);
  int m = strlen(pat);
  for(int s = 0;s < n - m + 1;++s)
  {
    int i = s,j = 0;
    for(;j < m-1;)
    {
      if(str[i] == pat[j])++i,++j;
      else break;
    }
    if(str[i] == pat[j])
      printf("%d\n",s);
  }
}

int main()
{
  str21();
}

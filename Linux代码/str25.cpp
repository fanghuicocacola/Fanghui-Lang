#include<stdio.h>
void str25()
{
    char l[100],s[100];
    int i,k=0,j=0,ssum=0,sum=0;
    printf("«Î ‰»Îs1:\n");
    fgets(l,100,stdin);
    fflush(stdin);
    printf("«Î ‰»Îs2:\n");
    fflush(stdin);
    gets(s);

    for(i=0;; i++)
    {
        if(s[i]=='\0')
            break;
        ssum++;
    }
    for(j=0;; j++)
    {
        if(l[j]=='\0')
        {
            break;
        }
        if(sum==ssum)
        {
            break;
        }
        if(l[j]==s[k])
        {
            sum++;
            k++;
            continue;
        }
        else
        {
            if(k==0 || j==0)
            {
                continue;
            }

            k=0;
            j-=1;
            sum=0;
            continue;
        }
    }
    if(sum==ssum)
        printf("TRUE");
    else
        printf("FALSE");
}
int main()
{
    str25();
}

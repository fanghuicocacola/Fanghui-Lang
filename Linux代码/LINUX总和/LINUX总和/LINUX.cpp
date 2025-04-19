#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"test.h"
int main()
{
    int c;
    printf("+----------------LINUX Big job----------------------+\n");
    printf("|             (1):String question                   |\n");
    printf("|             (2):Search/sort algorithm problem     |\n");
    printf("|             (3):School recruitment/ACM            |\n");
    printf("|             (4):Linux kernel programming          |\n");
    printf("+---------------------------------------------------+\n");
    printf("Please enter options \n");
    scanf_s("%d", &c);
    switch (c)
    {
    case 1:
        printf("You choose the string option\n");
        str_opt();
        break;
    case 2:
        printf("You choose search and sort options\n");
        sort_opt();
        break;
    case 3:
        printf("You choose the school recruitment and ACM option\n");
        acm_opt();
        break;
    case 4:
        printf("You choose the LINUX option\n");
        linux_opt();
        break;
    default:
        break;
    }
}

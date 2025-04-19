#include<stdio.h>
void select() {
    int i, j;
    int min;
    printf("please input number:\n");
    int a[100], length;
    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < length - 1; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            if (a[j] < a[min]) 
                min = j;
        }
        if (min != i) {
            int temp;
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    select();
}
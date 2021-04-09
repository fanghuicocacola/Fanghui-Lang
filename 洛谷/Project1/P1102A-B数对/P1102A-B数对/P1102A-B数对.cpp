#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int b[200001];
void insertionSort(int* a, int length) {
    int len = length;
    int temp;
    int i;//已排好序的序列的下一个元素（待插元素）的下标 
    int j;//有序序列的末尾下标 
    for (i = 1; i < len; i++) {
        temp = a[i];//中间变量 
        j = i - 1;
        while (j >= 0 && a[j] > temp) {//遍历有序序列，与要插入的元素比较 
            a[j + 1] = a[j];//将元素后移，满足条件后移一个位置
            j--;
        }
        a[j + 1] = temp; //插入  
    }
}

int main()
{
    int n, c, num = 0;
    scanf_s("%d %d", &n, &c);
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &b[i]);
    }
	insertionSort(b, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (b[j] - b[i] == c)
                num++;
            else if (b[j] - b[i] > c)
                break;
        }
    }
    printf("%d", num);
}


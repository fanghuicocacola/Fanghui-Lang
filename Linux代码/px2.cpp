#include<stdio.h>
int binarySearch(int a[], int low, int high, int value)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (value == a[mid])
        return mid;
    else if (value > a[mid])
        return binarySearch(a, mid + 1, high, value);
    else
        return binarySearch(a, low, mid - 1, value);
}

int Search(int a[], int low, int high, int value) 
{
    int mid = (low + high) / 2;

    if (a[mid] > a[low])
    {
        if (a[low] <= value && value <= a[mid])
        {
            return binarySearch(a, low, mid, value);
        }

        else                         
        {
            return Search(a, mid + 1, high, value);
        }
    }
    else       
    {
        if (a[mid] <= value && value <= a[high])
        {
            return binarySearch(a, mid, high, value);
        }
        else
        {
            return Search(a, low, mid - 1, value);
        }
    }
}

void px2()
{
    int a[] = { 3,4,5,6,7,8,9,0,1,2 };
    Search(a, 0, 9, 0);
}
int main()
{
    str30();
}

# include<iostream>
#define MAX 81
int arr[MAX] = {0};
int Merge(int a[],int ai,int b[],int bi) //功能：两个升序序列的合并
{
    int i = 0,j = 0,m = 0;
    while (i<ai&&j<bi)
    {
        if(a[i] <= b[j])
        {
            arr[m] = a[i];
            i++;
            m++;
        }
        else
        {
            arr[m] = b[j];
            j++;
            m++;
        }
    }
    while (i<ai)
    {
        arr[m] = a[i];
        i++;
        m++;
    }
    while (j<bi)
    {
        arr[m] = b[j];
        j++;
        m++;
    }
    return m;
}
int main()
{
    int a[10] = {1,2,3,4,5,6,8,10,22,44},b[10] = {1,2,4,15,33,44,78,100,120,190};
    int length = Merge(a,10,b,10);
    for(int i = 0;i<length;i++)
        std::cout<<arr[i]<<" ";
}
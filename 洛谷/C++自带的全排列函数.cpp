//#include <cstdio>
#include <iostream>
#include <algorithm>  //����ͷ�ļ� 
using namespace std;

int main()
{
    double a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0;
    do
    {
    	//���� 
        if( a[0] + a[1]/a[2] + (a[3]*100+a[4]*10+a[5])/(a[6]*100+a[7]*10+a[8]) == 10.0)
            count++;  // ����������/����ȣ� 
    }while( next_permutation(a, a+9));  //ȫ���к��� 
    printf("%d\n", count);
    return 0;
}

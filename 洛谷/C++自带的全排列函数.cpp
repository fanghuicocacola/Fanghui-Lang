//#include <cstdio>
#include <iostream>
#include <algorithm>  //排列头文件 
using namespace std;

int main()
{
    double a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0;
    do
    {
    	//规则 
        if( a[0] + a[1]/a[2] + (a[3]*100+a[4]*10+a[5])/(a[6]*100+a[7]*10+a[8]) == 10.0)
            count++;  // 操作（计数/输出等） 
    }while( next_permutation(a, a+9));  //全排列函数 
    printf("%d\n", count);
    return 0;
}

// P1017进制转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
using namespace std;
char z[20] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J' };
void change(int n, int m)
{
    if (n == 0)
    {
        return;
    }
    else 
    {
        if (n > 0 || n % m == 0) 
        { 
            change(n / m, m);
            printf("%c", z[n % m]);
            return; 
        }
        else
        { 
            change(n / m + 1, m); 
            printf("%c", z[-m + n % m]);
            return; 
        }
    }
}
int main()
{	
	int n, m;
	cin >> n >> m;
    cout << n << "=";
    change(n, m);
    cout << "(" << "base" << m << ")";
    return 0;

}

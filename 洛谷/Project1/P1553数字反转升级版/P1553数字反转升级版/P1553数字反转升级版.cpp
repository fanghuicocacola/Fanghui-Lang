// P1553数字反转升级版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int pp3 = 1;
int main()
{
    string s;
    bool p = true;
    int k1 = 0,k2 = 0,k3 = 0;
    int pp1 = 0,pp2 = 0,pp3 = 0;
    char s1[1001] = {}, s2[1001] = {};
    char c = {};
    cin >> s;
    if (s.length() == 1)
    {
        cout << s;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (p == true) {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    s1[k1] = s[i];
                    k1++;
                }
                else
                {
                    c = s[i];
                    p = false;
                    
                }
            }
            else
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    s2[k2] = s[i];
                    k2++;
                }
            }
        }
    }
    for (int i = k1 - 1; i >= 0; i--)
    {
        if (k1 == 1)
        {
            cout << s1[0];
            break;
        }
        if (s1[i] != '0')
        {
            pp1 = 1;
        }
        if (pp1 == 1)
        {
            cout << s1[i];
        }
    }
    cout << c;
    for (int i = k2 - 1; i >= 0; i--)
    {
        if (k2 == 1)
        {
            cout << s2[0];
            break;
        }
        if (pp3 == 0) {
            if (s2[k2 - 1 - i] == '0')
            {
                pp2++;
            }
            else
            {
                pp3 = 1;
            }
        }
        if(i>=pp2) 
        {
            cout << s2[i];
        }
    }
    return 0;
}


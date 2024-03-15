#include <iostream>
#include <stdio.h>
#include <stack>
#include <string> 
using namespace std;
stack<int> n;
int main()
{
    char buf[1000];
    gets_s(buf);
    int sum, k;
    for (int i = 0; buf[i] != '@'; i++)
    {
        if (buf[i] == '.')
        {
            sum = 0, k = 1;
            for (int j = i - 1; j >= 0 && buf[j] >= '0' && buf[j] <= '9'; j--)
            {
                sum = sum + (buf[j] - 48) * k;
                k *= 10;
            }
            n.push(sum);
            continue;
        }
        if (buf[i] >= '0' && buf[i] <= '9') 
            continue;
        sum = n.top();
        n.pop();
        if (buf[i] == '+') sum = n.top() + sum;
        if (buf[i] == '-') sum = n.top() - sum;
        if (buf[i] == '*') sum = n.top() * sum;
        if (buf[i] == '/') sum = n.top() / sum;
        n.pop();
        n.push(sum);
    }
    printf("%d\n", n.top());
}


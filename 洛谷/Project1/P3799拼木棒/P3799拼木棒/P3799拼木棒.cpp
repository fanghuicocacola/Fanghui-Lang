#include<iostream>

#define MOD 1000000007LL
using namespace std;
long long b[5011];
int main()
{
    int n;
    scanf_s("%d", &n);
    while (n--)//存下各个长度木棒的个数
    {
        int x;
        scanf_s("%d", &x);
        b[x]++;
    }
    long long ans = 0;
    for (int i = 1; i <= 5000; i++)
    {
        for (int j = i; j <= 5000; j++)
        {
            if (i + j > 5000)//没有满足的第三遍，直接跳出
                break;
            if (i == j)
            {
                if (b[i] >= 2 && b[i * 2] >= 2)//a,b,c(a=2i,b=2i,c=i+i)
                    ans = (ans + (b[i] * (b[i] - 1) / 2 * (b[i * 2] * (b[i * 2] - 1) / 2) % MOD)) % MOD;
            }
            else
            {
                if (b[i] >= 1 && b[j] >= 1 && b[i + j] >= 2)//a，b是长为i+j的木棍，c是长度i的木棍+长度j的木棍
                    ans = (ans + (b[i] * b[j] % MOD * (b[i + j] * (b[i + j] - 1) / 2) % MOD)) % MOD;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
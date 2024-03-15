#include<iostream>
#define MAXN 300  
#define maxn 200
using namespace std;
int n;
int cnt, s[maxn];  
struct big 
{
    int len, num[MAXN];  
}ans;
void jc(int x)  
{
    int t = 0;  
    for (int i = 1; i <= ans.len; ++i) 
    {
        ans.num[i] = ans.num[i] * x + t; 
        t = ans.num[i] / 10;  
        ans.num[i] %= 10;
    }
    while (t)
    {
        ans.num[++ans.len] = t % 10;
        t /= 10;
    }
    return;
}
int main()
{
    cin >> n;
    int sum = 0, now = 1; 
    cnt = 0;
    while (sum <= n) {
        sum += ++now;
        s[++cnt] = now;
    }
    if (sum > n) 
        while (sum <= n) {
            sum += ++now;
            s[++cnt] = now;
        }
    {
        if (sum - n == 1) 
            s[1] = -1; 
        else 
            s[sum - n - 1] = -1; 
    }
    ans.len = 1;  
    ans.num[1] = 1;
    if (n <= 4)
    {
        cout << "1" << " " << n - 1;
        puts("");
        cout << n - 1;
    }
    else
    {
        for (int i = 1; i <= cnt; ++i)
            if (s[i] != -1)
                printf("%d ", s[i]), jc(s[i]);
        puts("");
        for (int i = ans.len; i >= 1; --i)
            printf("%d", ans.num[i]);
        puts("");
    }
    return 0; 
}
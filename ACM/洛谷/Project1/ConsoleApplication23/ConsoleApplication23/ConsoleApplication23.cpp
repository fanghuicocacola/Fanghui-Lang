#include<iostream>
#include<string.h>
#include<math.h>
#define min(a,b) ( ((a)>(b)) ? (b):(a) )
using namespace std;
long long int s[11], b[11], k[11];    
long long int n, S = 1, B = 0, ans = 99999999999;      
void dfs(int x)
{
    if (x > n)
    {

    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (k[i])   
            {
                S *= s[i];
                B += b[i];
                ans = min(ans, abs(S - B)); 
                k[i] = 0;    
                dfs(x + 1);
                k[i] = 1;   
                S /= s[i];
                B -= b[i];
            }
        }
    }
}
int main()
{
    cin >> n;
    memset(k, 1, sizeof(k));
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> b[i];
    }
    dfs(1);
    cout << ans;
}
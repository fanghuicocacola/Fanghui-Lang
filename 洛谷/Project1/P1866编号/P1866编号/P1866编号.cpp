#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, i, MaxNumber[51] = {};
	long long ans = 1; 
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> MaxNumber[i];
	}
	sort(MaxNumber + 1, MaxNumber + n + 1);
	for (i = 1; i <= n; i++) 
	{ 
		ans *= (MaxNumber[i] - i + 1); 
		ans %= 1000000007; 
	}  
	cout << ans << endl; 
	return 0;
}

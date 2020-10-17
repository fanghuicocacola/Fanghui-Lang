#include <iostream>

using namespace std;

long long a, b, c;

long long maxgyc(long long x, long long y) 
{
	// 辗转相除法
	if (x % y == 0) 
		return y;
	return maxgyc(y, x % y);//重点
}

long long mingbc(long long x, long long y)
{	//最小公倍数:相乘除以最大公约数
	return x * y / maxgyc(x, y);
}

int main()
{
	scanf("%lld%lld%lld", &a, &b, &c);
	long long ans = 0;
	ans = mingbc(a, mingbc(b, c));
	cout << ans << endl;
	return 0;
}


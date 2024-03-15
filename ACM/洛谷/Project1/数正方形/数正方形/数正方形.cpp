#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main() {
	int N, M,n;
	cin >> N >> M;
	int cnt = 0;
	n = min(N, M);
	for (int i = 0; i < n; i++)
	{
		cnt += (N-i)*(M-i);
	}
	cout << cnt;
	return 0;
}
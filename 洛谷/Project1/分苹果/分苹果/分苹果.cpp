#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int M, N, R, L, C;
	cin >> N >> M;
	vector<int>children(N + 2);
	for (int i = 0; i < M; i++)
	{
		cin >> R >> L >> C;
		children[R] += C;
		children[L + 1] -= C;
	}
	for (int i = 1; i <= N; i++)
		cout << children[i];
	for (int i = 1; i <= N; i++)
	{
		children[i] += children[i - 1];
		cout << children[i] << ' ';
	}
	return 0;
}


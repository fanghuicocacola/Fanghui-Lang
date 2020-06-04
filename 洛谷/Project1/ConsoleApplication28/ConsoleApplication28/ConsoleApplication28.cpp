#include<iostream>
#include<stdio.h>
using namespace std;
int n, a, b;
string c;
char cc;
int size(int n)
{
	int x = 0;
	if (n == 0)
		return 1;
	if (n > 0)
		while (n) {
			n /= 10;
			++x;
		}
	if (n < 0) {
		x = 1;
		n = -n;
		while (n) {
			n /= 10;
			++x;
		}
	}
	return x;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c;
		int x = 0;
		switch (c[0]) {
		case 'a': cin >> a >> b;
			printf("%d+%d=%d\n", a, b, a + b); x = size(a + b) + 2;
			cc = c[0]; break;
		case 'b': cin >> a >> b;
			printf("%d-%d=%d\n", a, b, a - b); x = size(a - b) + 2;
			cc = c[0]; break;
		case 'c': cin >> a >> b;
			printf("%d*%d=%d\n", a, b, a * b); x = size(a * b) + 2;
			cc = c[0]; break;
		default:
			cin >> b;
			a = 0;
			int l = c.size();
			for (int i = 0; i < l; ++i)
				a = a * 10 + c[i] - '0';
			switch (cc) {
			case 'a':
				printf("%d+%d=%d\n", a, b, a + b); x = size(a + b) + 2; break;
			case 'b':
				printf("%d-%d=%d\n", a, b, a - b); x = size(a - b) + 2; break;
			case 'c':
				printf("%d*%d=%d\n", a, b, a * b); x = size(a * b) + 2; break;
			default:break;
			}
			break;
		}
		x = size(a) + size(b) + x;
		printf("%d\n", x);
	}
	return 0;
}
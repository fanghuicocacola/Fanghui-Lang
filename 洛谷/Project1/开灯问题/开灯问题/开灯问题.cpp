#include<iostream>
using namespace std;
int a[2000001], n;
double x, y;
int main() {
	cin >> n;
	int i;
	for (i = 1; i <= n; i++) {
		cin >> x >> y;
		for (int j = 1; j <= y; ++j) {
			if (a[int(j * x)] == 0) 
				a[int(j * x)] = 1;
			else a[int(j * x)] = 0;
		}
	}
	i = 1;
	while(1)
	{
		i++;
		if (a[i] == 1) {
			cout << i;
			break;
		}
	}
	return 0;
}


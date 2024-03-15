#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int n = 0,k;
	double Sn = 0.00000;
	cin >> k;
	while (Sn <= k)
	{
		n++;
		Sn += 1.00000 / n;
	}
	cout << n;
}

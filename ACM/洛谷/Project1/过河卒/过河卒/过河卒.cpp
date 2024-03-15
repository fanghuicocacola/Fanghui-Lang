#include<iostream>
#include<stdio.h>

using namespace std;
long long f[25][25];
bool g[25][25];

int main() {
	int x1, y1, x2, y2;
	scanf_s("%d %d", &x1, &y1);
	scanf_s("%d %d", &x2, &y2);
	g[x2][y2] = 1;
	if (x2 > 1 and y2 != 0)   g[x2 - 2][y2 - 1] = 1;
	if (x2 < 19 and y2 != 0)  g[x2 + 2][y2 - 1] = 1;
	if (x2 > 1 and y2 != 20)  g[x2 - 2][y2 + 1] = 1;
	if (x2 < 19 and y2 != 20) g[x2 + 2][y2 + 1] = 1;
	if (x2 != 0 and y2 > 1)   g[x2 - 1][y2 - 2] = 1;
	if (x2 != 0 and y2 < 19)  g[x2 - 1][y2 + 2] = 1;
	if (x2 != 20 and y2 > 1)  g[x2 + 1][y2 - 2] = 1;
	if (x2 != 20 and y2 < 19) g[x2 + 1][y2 + 2] = 1;
	for (int i = 0; i <= x1; ++i)
		for (int j = 0; j <= y1; ++j)
			if (!g[i][j]) { 
				if (i == 0 and j == 0)
					f[0][0] = 1;
				else if (i == 0 and j > 0)
					f[0][j] = f[0][j - 1];
				else if (i > 0 and j == 0)
					f[i][0] = f[i - 1][0];
				else
					f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
	printf_s("%lld\n", f[x1][y1]);
	return 0;
}
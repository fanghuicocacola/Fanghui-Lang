#include<stdio.h>
int a[11];
int main()
{
	int j, m, n;
	scanf_s("%d%d", &m, &n);
	for (int i = m; i <= n; i++) {
		j = i;
		while (j > 0) {
			a[j % 10]++;
			j = j / 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
}

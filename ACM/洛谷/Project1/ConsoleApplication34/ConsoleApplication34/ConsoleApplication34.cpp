#include<stdio.h>

int f[5005];
int zuxian(int x)
{
	if (x == f[x])
		return x;
	return f[x] = zuxian(f[x]);
}
int main()
{
	int a, b;
	int n, m, p;
	scanf_s("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; i++)
		f[i] = i;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &a, &b);
		f[zuxian(a)] = zuxian(b);
	}
	for (int i = 0; i < p; i++)
	{
		scanf_s("%d%d", &a, &b);
		if (zuxian(a) == zuxian(b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
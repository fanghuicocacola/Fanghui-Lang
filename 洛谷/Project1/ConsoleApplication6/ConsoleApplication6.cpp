#include<stdio.h>
int a[250];
int main()
{
	int i, j, k, n,temp;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
		j = 0;
		for (k = 0; k < i; k++) {
			if (a[i] > a[k])
				j++;
		}
		printf("%d ", j);
	}

}

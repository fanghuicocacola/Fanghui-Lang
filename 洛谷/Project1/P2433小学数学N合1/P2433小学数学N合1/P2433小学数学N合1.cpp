#include <iostream>
#include <stdio.h>

int main()
{
	int n, min = 9999, max = 0, m1 = 0, m2 = 0;
	float a[1002], sum = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%f", &a[i]);
		if (min > a[i]) {
			min = a[i];
			m1 = i;
		}
		if (max < a[i]) {
			max = a[i];
			m2 = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != m1 && i != m2) {
			sum += a[i];
		}
	}
	printf_s("%.2f", sum / (1.0*(n - 2)));
}

#include<stdio.h> 
double ave[101], max2 = 0;
int main()
{
	int m, n, max1 = -1, min1 = 11, sum = 0;
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		sum = 0;
		min1 = 11, max1 = -1;
		int tmp;
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &tmp);
			if (max1 < tmp)
				max1 = tmp;
			if (min1 > tmp)
				min1 = tmp;
			sum += tmp;
		}
		ave[i] = (double)(sum - min1 - max1) / (double)(m - 2);
	}
	for (int i = 0; i < n; i++) {
		if (max2 < ave[i])
			max2 = ave[i];
	}
	printf("%.2lf", max2);
}

#include <stdio.h>

int main()
{
	int n, a[101], b[101], k = 0, nn = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
		
		bool k = true;
		if (a[i] == 1)
			continue;
		for (int j = 2; j*j <= a[i]; j++)
		{
			
			if (a[i] % j == 0)
			{
				k = false;
				break;
			}
			
		}
		if (k)
			b[nn++] = a[i];
	}
	for (int i = 0; i < nn; i++)
		printf("%d ", b[i]);
}


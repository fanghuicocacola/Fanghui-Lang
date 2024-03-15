#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n-1 ; i++)
	{
		ans += (a[i] + a[i + 1]);
		a[i + 1] += a[i];
		for (int j = i + 1; j < n-1; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
			else
				break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

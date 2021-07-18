#include <stdio.h>

void acm19() {
	int n;
	scanf_s("%d",&n);
	float t;
	for (int i = 1; i <= 10000000; i++) {
		t = i;
		for (int j = 1; j < n; j++) {
			t -= t / 2.0 + 1;
		}
		if (t == 1) {
			printf("%d",i);
			break;
		}
	}
}
int main()
{
	acm19();
}
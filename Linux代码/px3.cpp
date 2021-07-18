#include <stdio.h>

int getIndexofIncArray(int* a, int M, int N, int target, int* x, int* y) {
	int i = 0, j = M - 1, count;
	*x = *y = -1;
	for (count = 0; count < N + M; count++) {
		if (target == *(a + N * j + i)) {
			*x = j;
			*y = i;
			printf("true");
		}
		else	if (target > *(a + N * j + i)) {
			if ((i >= N) && (j < 0)) {
				break;
			}
			else {
				i++;
			}
		}
		else {
			if ((i >= N) && (j < 0)) {
				break;
			}
			else {
				j--;
			}
		}
	}
	printf("false");
}

void  px3() {
	int i, j;
	int target;
	int* p1 = &i, * p2 = &j;
	int a[4][5] = {
		{1, 3, 7, 11, 19},
		{2, 7, 10, 29, 30},
		{13, 28, 54, 69, 90},
		{46, 57, 78, 98, 101}
	};
	printf("please input");
	scanf("%d", &target);
	getIndexofIncArray(&a[0][0], 4, 5, target, p1, p2);
	printf("%d, %d\n", i, j);
}

int main()
{
	px3();
}
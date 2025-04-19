#include<stdio.h>
#include<stdlib.h>

void acm18() {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			printf("%2d x%2d = %-2d ", j, i, i * j);

		}
		printf("\n");
	}
}

int main() {
	acm18();
}


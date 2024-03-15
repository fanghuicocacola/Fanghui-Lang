#include<stdio.h>

int main() {
	int a, b,c,d;
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	int x, y;
	x = c - a;
	y = d - b;
	if (y >= 0) {
		printf_s("%d %d", x, y);
	}
	else {
		x = x - 1;
		y = y+60;
		printf_s("%d %d",x , y);
	}
	return 0;
}

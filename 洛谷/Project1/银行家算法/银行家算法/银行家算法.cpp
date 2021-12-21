#include <stdio.h>

int main() {
	int a[5] = { 1,2,5,7,3 };
	int* p = a;
	int* q = &a[0];
	printf("*p = %d\n&a = %p\nq = %p\n", *p, &a, q);
	printf("q++ = %p\n", q++);
	printf("p++ = %p\n*q++ = %d\n*p++ = %d\n", p, *q++, *p++);
	printf("*p+=4%d", *p += 4);

}
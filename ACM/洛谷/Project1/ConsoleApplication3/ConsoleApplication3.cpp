
#include <stdio.h>

int main()
{
	int all=0, cast, self=0;
	for (int mouths = 1; mouths <= 12; mouths++) {
		scanf_s("%d", &cast);
		self = self + 300 - cast;
		if (self < 0) {
			printf("-%d", mouths);
			return 0;
		}
		if (self>=100) {
			all = all +(self-self%100)/100;
			self = self % 100;
		}
	}
	printf("%d",all * 120+self);
	return 0;
}



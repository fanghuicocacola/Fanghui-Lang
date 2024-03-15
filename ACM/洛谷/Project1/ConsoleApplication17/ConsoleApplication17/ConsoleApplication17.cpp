#include <stdio.h>
#include <string.h>
int main()
{
	char a;
	int n = 0;
	while (scanf_s("%c", &a) != EOF)
	{
		if (a == 'a')
			n += 1;
		if (a == 'b')
			n += 2;
		if (a == 'c')
			n += 3;
		if (a == 'd')
			n += 1;
		if (a == 'e')
			n += 2;
		if (a == 'f')
			n += 3;
		if (a == 'g')
			n += 1;
		if (a == 'h')
			n += 2;
		if (a == 'i')
			n += 3;
		if (a == 'j')
			n += 1;
		if (a == 'k')
			n += 2;
		if (a == 'l')
			n += 3;
		if (a == 'm')
			n += 1;
		if (a == 'n')
			n += 2;
		if (a == 'o')
			n += 3;
		if (a == 'p')
			n += 1;
		if (a == 'q')
			n += 2;
		if (a == 'r')
			n += 3;
		if (a == 's')
			n += 4;
		if (a == 't')
			n += 1;
		if (a == 'u')
			n += 2;
		if (a == 'v')
			n += 3;
		if (a == 'w')
			n += 1;
		if (a == 'x')
			n += 2;
		if (a == 'y')
			n += 3;
		if (a == 'z')
			n += 4;
		if (a == ' ' || a == '*' || a == '#')
			n += 1;

	}
	printf("%d",n);
}


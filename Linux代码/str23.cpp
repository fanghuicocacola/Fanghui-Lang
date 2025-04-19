#include <stdio.h>
#include <string.h>
void str23()
{
	char str[30];
	int strtoint[30];
	fgets(str, 100, stdin);
	int i = 0;
	while (str[i] != '\0')
	{
		strtoint[i] = str[i] - 48;
		i++;
	}
	for (int i = 0; i < strlen(str)-1; i++)
	{
		printf("%d", strtoint[i]);
	}
}
int main()
{
	str23();
}


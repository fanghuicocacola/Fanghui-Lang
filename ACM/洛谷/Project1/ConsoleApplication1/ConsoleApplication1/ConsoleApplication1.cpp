#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
char a[81];
void read()
{
	char ch;
	int i = 0;
	while ((ch = getchar()) && ch != EOF)
	{
		a[i++] = ch;
	}
}

int main() {
	int i;
	read();
	for (i = 0; a[i] != '\0'; i++) {
		if (a[0] <= 'z' && a[0] >= 'a') {
			a[0] -= 32;
		}
		else if (a[i] == '.') {
			if ((a[i + 1] >= 'A' && a[i + 1] <= 'Z') || !(a[i + 1] == ' ')) {
				i++;
				if (a[i + 1] >= 'a' && a[i + 1] <= 'z') {
					a[i + 1] -= 32;
				}
			}
		}
	}
	puts(a);
}
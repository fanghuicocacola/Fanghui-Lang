#include <iostream>
using namespace std;
int main()
{
	int a;
	int b, lengh = 1, n;
	for (int i = 2; i < 10000; i++)
	{
		a = i * i;
		b = i;
		while (b > 0)
		{
			b /= 10;
			lengh *= 10;
		}
		n = a % lengh;
		if (i == n) 
		{
			printf("%d   ", lengh);
			cout << i << endl;
		}
		lengh = 1;
	}
}



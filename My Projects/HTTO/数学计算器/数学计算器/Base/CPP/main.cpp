#include "../polynomial.h"
#include "../Count.h"
#include "../equation.h"
#include <time.h>
#include "../factorization.h"
#include "../rational_fraction.h"
#include "../Examples/polynomial_counter.h"
#ifdef _WIN32
#include <Windows.h>
#include<psapi.h>

//@ ⁰
//b*[^:b#/]+.*$
#endif
int main()
{
	using namespace Htto;
	using namespace std;
	clock_t start, finish;
	double total;
	start = clock();
	try
	{
		std::string input;
		std::cin >> input;
		std::cout << Count::SimpleCount::Rational_fraction_count(input).ToString();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << "\n\n======================================\n\n";
	try
	{
		//Example::polynomial_counter();
	}
	catch (std::exception & e)
	{
		/*		Polynomial p1;
		p1=Htto::Count::SimpleCount::PolyCount("(18111/2)x^4-90555x^3+(633885/2)x^2-452773x+217331");
		std::map<std::string, Fraction> m;
		for (int i = 1;i < 10;i++)
		{
			m["x"] = Fraction(i);
			std::cout <<p1.get_value(m)<<std::endl;
		}*/
		std::cout << e.what();
	}
	finish = clock();
	total = (double)(finish - start);
	cout << "\nTIME:" << total;
	while (1)
		std::cin.get();
	return 0;
}

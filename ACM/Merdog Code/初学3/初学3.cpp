#include <iostream>
/*
*	iostream:输入输出
	i -> input
	o -> output
	stream 流
*/
// 


void mul()
{
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << v1 << "*" << v2 << "is" << v1 * v2 << std::endl;//单行注释的练习
}

void if_test()
{
	int tmp = 0;
	std::cin >> tmp;
	if (tmp > 100)
	{
		std::cout << "what you input is larger than 100";
	}
	else
	{
		std::cout << "less than 100";
	}
}



int main()
{
	int sum = 0;
	int i = 0;
	while (i < 101)
	{
		sum += i;
		i += 1;
	}
	std::cout << sum;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
/*
	homework:
	1. 计算1，3，5，7，9，101的和
	2. 输入你的你的名字，输出 Hi+你的名字
	3. 输入三个数，并计算Δ，如果Δ<0，输出 delta < 0;
*/



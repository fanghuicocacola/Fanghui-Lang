// P1068分数线.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Person
{
    int num;
    int score;
};
Person p[5100];
int cmp(Person p1, Person p2) {
	if (p1.score > p2.score) {
		//比成绩
		return true;
	}
	else if (p1.score == p2.score) {
		if (p1.num < p2.num)
			return true;
		//比较报名号
		else return false;
	}
	else return false;
}
int main()
{
    int n, m;
    scanf_s("%d %d", &n, &m);
	m = floor(m * 1.5);
	for (int i = 0; i < n; i++) {
		scanf_s("%d%d", &p[i].num, &p[i].score);
	}
	sort(p, p + n, cmp);
	int fenshuxian = p[m - 1].score;
	int renshu = m;
	for (int i = m; i < n; i++) {
		if (p[i].score == fenshuxian)
			renshu += 1;
		else if (p[i].score < fenshuxian)
			break;
	}
	printf("%d %d\n",fenshuxian,renshu);
	for (int i = 0; i < renshu; i++) {
		printf("%d %d\n", p[i].num, p[i].score);
	}
	return 0;
}



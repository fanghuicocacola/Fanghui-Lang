#include<iostream>
#include<stdio.h>

using namespace std;
struct stu
{
	int num;
	int c, m, e;
	int sum;
}students[301];
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		students[i].num = i;
		scanf_s("%d %d %d", &students[i].c, &students[i].m, &students[i].e);
		students[i].sum = students[i].c + students[i].e + students[i].m;
	}
	for (int i = 1; i <= n-1; i++)
	{
		for (int j = 1; j <= n - i; j++) {
			if (students[j].sum < students[j + 1].sum)
			{
				swap(students[j].num, students[j + 1].num);
				swap(students[j].c, students[j + 1].c);
				swap(students[j].sum, students[j + 1].sum);
			}
			if (students[j].sum == students[j + 1].sum && students[j].c < students[j + 1].c)
			{
				swap(students[j].num, students[j + 1].num);
				swap(students[j].c, students[j + 1].c);
				swap(students[j].sum, students[j + 1].sum);
			}
			if (students[j].sum == students[j + 1].sum && students[j].c == students[j + 1].c && 
				students[j].num > students[j + 1].num)
			{
				swap(students[j].num, students[j + 1].num);
				swap(students[j].c, students[j + 1].c);
				swap(students[j].sum, students[j + 1].sum);
			}
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		printf("%d %d\n", students[i].num, students[i].sum);
	}

}

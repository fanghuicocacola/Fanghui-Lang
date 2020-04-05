#include<stdio.h>
#include<string.h>
struct student
{
	unsigned int stu_study, stu_other;
	double score;
	int num;
	void input()
	{
		scanf_s("%d%d%d", &num, &stu_study, &stu_other);
		score = stu_study * 1.0 * 0.7 + stu_other * 1.0 * 0.3;
	}
	void stus()
	{
		score = stu_study * 1.0 * 0.7 + stu_other * 1.0 * 0.3;
		if ((stu_study + stu_other) > 140 && score >= 80)
		{
			printf("Excellent\n");
		}
		else
		{
			printf("Not excellent\n");
		}
	}

}stu[1000];
int main(void)
{
	int n, i;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		stu[i].input();
	}
	for (i = 0; i < n; i++)
	{
		stu[i].stus();
	}
	return 0;
}
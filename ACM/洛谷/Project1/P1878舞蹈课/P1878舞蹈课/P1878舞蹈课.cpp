#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
#define inf 999999999
int ans[200005][2], sum = 0;
struct node
{
	int l, r, cha, num;
	bool judge;
}a[200005];
bool operator<(node rr, node ll)//优先队列有限法则 
{
	int lll = abs(ll.cha), rrr = abs(rr.cha);
	if (rrr != lll)
		return lll < rrr;
	else
		return ll.num < rr.num;
}

priority_queue <node> q;

int main()//输入人数，判断性别，judge=0,男，=0，女，=1
{//记录技术值（换成now，next的差值，存入a[i].cha,a[i].num存自身位置，
	int n, now, next, t = 0;
	char x;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >>x;
		if (x == 'B') 
			a[i].judge = 0;
		else 
			a[i].judge = 1;
	} //性别存入 
	scanf_s("%d", &now);
	for (int i = 1; i < n; i++)
	{
		scanf_s("%d", &next);
		a[i].num = i;	 		 
		a[i].cha = next - now; 
		a[i].l = i - 1; a[i].r = i + 1;
		q.push(a[i]);
		now = next;
	}//技术值存入，并计算差值
	a[n].r = n + 1; a[n].num = n; a[n].cha = inf;//因为是最后一个人了，右边实际上没人，差值inf
	while (!q.empty())
	{
		int xx = q.top().num, cmp = q.top().cha;
		q.pop();//取出栈顶元素并删除
		int yy = a[xx].r;
		if (a[xx].cha == cmp 
			&& a[xx].judge != a[yy].judge//本身和他右边的是否为异性
			&& xx != 0 //不是最左边的
			&& yy != n + 1)//不是最左边的
		{
			ans[++t][0] = xx; ans[t][1] = yy;//++t先进行自增，再计算表达式，t表示一个数，1是它（0）的右值
			a[a[xx].l].cha += a[xx].cha + a[yy].cha;//差值更新
			a[a[yy].r].l = a[xx].l; // 例a b c d删去b c 
			a[a[xx].l].r = a[yy].r;
			if (a[xx].l > 0 && a[yy].r <= n)
				q.push(a[a[xx].l]);
			a[xx].l = a[xx].r = a[yy].l = a[yy].r = n + 1;//比较过的先筛选掉
		}
	}
	printf("%d\n", t);
	for (int i = 1; i <= t; i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}
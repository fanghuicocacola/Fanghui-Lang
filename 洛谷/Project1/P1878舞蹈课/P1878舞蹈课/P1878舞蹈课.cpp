#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
#define inf 2000000000
int ans[200005][2], sum = 0;
struct node//链表 
{
	int l, r, cha, xu;
	bool judge;
}a[200005];

bool operator<(node rr, node ll)//优先队列有限法则 
{
	int lll = abs(ll.cha), rrr = abs(rr.cha);
	if (rrr != lll)
		return lll < rrr;
	else
		return ll.xu < rr.xu;
}

priority_queue <node> que;

int main()
{
	int n, now, next, t = 0;
	char x;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x == 'B') a[i].judge = 0;
		else a[i].judge = 1;
	} //以上性别判断 
	scanf_s("%d", &now);
	for (int i = 1; i < n; i++)
	{
		scanf_s("%d", &next);
		a[i].xu = i;	 		//自身是第几个 
		a[i].cha = next - now;//预处理技术值差 
		a[i].l = i - 1; a[i].r = i + 1;//预处理左右 
		que.push(a[i]);
		now = next;
	}
	a[n].r = n + 1; a[n].xu = n; a[n].cha = inf;
	while (!que.empty())//开始模拟过程 
	{
		int xx = que.top().xu, cmp = que.top().cha;
		que.pop();
		int yy = a[xx].r;
		if (a[xx].cha == cmp/*判断是否是更新过的*/ && a[xx].judge != a[yy].judge/*一男一女*/
			&& xx != 0 && yy != n + 1/*特判链表首尾 */)
		{
			ans[++t][0] = xx; ans[t][1] = yy;
			a[a[xx].l].cha += a[xx].cha + a[yy].cha;//更新差值 
			a[a[yy].r].l = a[xx].l; a[a[xx].l].r = a[yy].r;//断链重连 
			if (a[xx].l > 0 && a[yy].r <= n)//特判链表首尾 
				que.push(a[a[xx].l]);//入队列 
			a[xx].l = a[xx].r = 0; a[yy].l = a[yy].r = n + 1;
		}
	}
	printf("%d\n", t);
	for (int i = 1; i <= t; i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}
#include <iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
struct Edge
{
    int z;//此边的子节点
    int val;//此边的权值
    int nexty;
}edge[1000000];
int head[20000];
int cnt = 0;//边编号
inline void add(int a, int b, int c)//存边
{
    cnt++;
    edge[cnt].z = b;
    edge[cnt].val = c;
    edge[cnt].nexty = head[a];
    head[a] = cnt;//更新head
}
int main()
{
    bool visited[20000] = { 0 };//是否作为过起点
    long long dis[20000];//距离
    int n, m, s;
    int a, b, c;
    scanf_s("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; i++)dis[i] = 2147483647;
    for (int i = 0; i < m; i++)
    {
        scanf_s("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int curr = s;
    dis[s] = 0;//起始点到起始点距离为0
    long long INF;
    while (!visited[curr])
    {
        visited[curr] = true;//已做过起点
        for (int i = head[curr]; i != 0; i = edge[i].nexty)
        {
            if (!visited[edge[i].z] && dis[edge[i].z] > dis[curr] + edge[i].val)
                dis[edge[i].z] = dis[curr] + edge[i].val;//更新操作
        }
        INF = 2147483647;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && INF > dis[i])//取新的最小值
            {
                INF = dis[i];
                curr = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ", dis[i]);
    return 0;
}

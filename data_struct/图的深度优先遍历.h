#include<stdio.h>
#include<iostream>
#define MAX_VERTEX_NUM 100
bool visited[MAX_VERTEX_NUM];     //访问标记数组

void DFSTraverse(Graph G){        //对图G进行深度优先遍历
    for (int v = 0; v < G.vexnum; ++v)
        visited[v]=false;         //初始化已访问标记数据
    for(int v=0;v<G.vexnum;++v)       //本代码中是从v=0开始遍历
        if(!visited[v])
            DFS(G,v);

}
void DFS(Graph G,int v){          //从顶点v出发，深度优先遍历图G
    visit(v);                     //访问顶点v
    visited[v]=true;              //设已访问标记
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
    {
        if(!visited[w]){          //w为u的尚未访问的邻接顶点
            DFS(G,w);
        }
    }
}
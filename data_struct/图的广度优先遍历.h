#include"图的存储.h"
#include<stdio.h>
#include<iostream>
#define MAX_VERTEX_NUM 100
bool visited[MAX_VERTEX_NUM];      //访问标记数组
void BFSTraverse(Graph G){         //对图G进行广度优先遍历
    for(int i=0;i<G.vexnum;++i)
        visited[i]=false;
    InitQueue(Q);
    for(int i=0;i<G.venxum;++i){
        if(!visited[i])
            BFS(G,i);
    }
}
//广度优先遍历
void BFS(Graph G,int v){           //从顶点v出发，广度优先遍历图G
    visit(v);
    visited[v]=TRUE;
    Enqueue(Q,v);
    while (!isEmpty(Q))
    {
        Dequeue(Q,v);
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
        {
            //检测所有邻接点
            if(!visited[w]){        //w为v的尚未访问的邻接顶点
                visit(w);           //访问顶点w
                visited[w]=TRUE;    //对w做已访问标记
                Enqueue(Q,w);       //顶点w入队
            }
        }
    }
}
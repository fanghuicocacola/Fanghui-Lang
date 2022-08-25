#include<stdio.h>
#include<iostream>

bool visited[MAX_VERTEX_NUM];      //访问标记数组
//广度优先遍历
void BFS(Graph G,int v){           //从顶点v出发，广度优先遍历图G
    visit(v);                      //访问初始顶点v
    visited[v]=true;               //对v做已访问标记
    Enqueue(Q,v);                  //顶点v入队列Q
    while (!isEmpty(Q))            //BFS算法主过程
    {                         
        Dequeue(Q,v);              //队头元素u出队
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
        {
            //检测v所有邻接点
            if(!visited[w]){        //w为v的尚未访问的邻接顶点
                visit(w);           //访问顶点w
                visited[w]=true;    //对w做已访问标记
                Enqueue(Q,w);       //顶点w入队列
            }
        }
    }
}
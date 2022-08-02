//邻接矩阵
#define MaxVertexNum 100                    //顶点数目的最大值
typedef struct {
    char Ver[MaxVertexNum];                 //顶点表
    int Edge[MaxVertexNum][MaxVertexNum];   //邻接矩阵，边数
    int vexnum,arcnum;                      //图的当前顶点数和边数/弧数
};

#define INFINITY 99999999                   //宏定义常量“无穷”
typedef char VertexType;                    //顶点的数据类型
typedef int EdgeType;                       //带权图中边上权值的数据类型
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;

//邻接表
//“边/弧”
typedef struct ArcNOde{
    int adjvex;          //边/弧指向哪个结点
    struct ArcNode *next;//指向下一条弧的指针
    //INfoType info      //边权值
}ArcNode;
//“顶点”
typedef struct VNode
{
    VertexType data;     //顶点信息
    ArcNode *first;      //第一条边/弧
}VNode,AdjList[MaxVertexNum];
//用邻接表存储的图
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;






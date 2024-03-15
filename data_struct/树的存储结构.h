#define MAX_TREE_SIZE 100
typedef int ElemType;               //树中最多结点数
//双亲表示法
typedef struct PTNode{                     //树的结点定义
    ElemType data;                  //数据元素
    int parent;                     //双亲位置域
}PTNode;
typedef struct PTree{                     //树的类型定义
    PTNode nodes[MAX_TREE_SIZE];    //双亲表示
    int n;                          //结点数
} PTree;
//孩子表示法
typedef struct CTNode{
    int child;             //孩子结点在数组中的位置
    CTNode *next;   //下一个孩子
} CTNode;
typedef struct CTBox{
    ElemType data;
    CTNode *firstChild;
} CTBox;
typedef struct CTree{
    CTBox nodes[MAX_TREE_SIZE];
    int n,r;            //结点数和根的位置
} CTree;

//孩子兄弟表示法
typedef struct CSNode{
    ElemType data;                              //数据域
    CSNode *firstchild,*nextsibling;    //第一个孩子和右兄弟指针
}CSNode;
//类比----二叉树的结点（链式存储）
typedef struct BiTNode{
    ElemType data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;





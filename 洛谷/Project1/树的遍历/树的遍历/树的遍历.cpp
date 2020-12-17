#include <iostream>
using namespace std;
typedef int Status;
#define OK 1
#define MAXSIZE 200
//1.	二叉树的基本操作算法实现
//（1）利用二叉树字符串“A(B(D, E(H(J, K(L, M(, N))))), C(F, G(, I)))”创建二叉树的二叉链式存储结构；
//（2）输出该二叉树；
//（3）输出‘H’节点的左、右孩子结点值；
//（4）输出该二叉树的结点个数、叶子结点个数、二叉树的度和高度；

//定义二叉树结构
typedef struct Node
{
	char data;
	struct Node* lchild, * rchild;  //定义左右
}*BiTree, BiTNode;

//定义链栈结构
typedef struct SNode
{
	BiTNode* data;
	struct SNode* next;
}*LinkStack, SNode;


//构造一个空的链表
Status InitBiTree(BiTree& T)
{
	T = NULL;
	return OK;
}

//链栈的初始化
Status InitStack(LinkStack& S)
{
	S = NULL;
	return OK;
}

//入栈
Status PushStack(LinkStack& S, BiTNode* T)
{
	SNode* p = new SNode;
	p->data = T;
	p->next = S;
	S = p;
	return OK;
}

//出栈
Status PopStack(LinkStack& S, BiTNode*& T)
{
	if (S == NULL) cout << "空栈" << endl;
	T = S->data;
	SNode* p = S;
	S = S->next;
	delete p;
	return OK;
}

//判断是否为空栈
bool Empty(LinkStack S)
{
	if (S == NULL) return true;
	else return false;
}

//获取栈顶元素
BiTNode* Gettop(LinkStack& S)
{
	if (S != NULL) return S->data;
	else return NULL;
}


Status CreateBiTree(BiTree& T)
{
	BiTree S[MAXSIZE];    //顺序栈，便于回溯
	BiTNode* p = NULL;
	int top = 0, k = 0;  //top表示一维数组的下标；
	char ch;
	cin >> ch;
	while (ch != '#')
	{
		switch (ch)
		{
		case '(':S[++top] = p; k = 1; break;  //top++为入栈，k=1为左子树；
		case ')':top--; break;     //top--为出栈；
		case ',':k = 2; break;     //k=2为右子树

		default:
			p = new BiTNode;
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (T == NULL) T = p;
			else
			{
				switch (k)
				{
				case 1:S[top]->lchild = p; break;
				case 2:S[top]->rchild = p;  break;
				}
			}
			break;
		}
		cin >> ch;//A(B(D, E(H(J, K(L, M(, N))))), C(F, G(, I)))#
	}
	return OK;
}

//先序遍历的递归
Status PreBiTree(BiTree T)
{
	if (T != NULL)
	{
		cout << T->data << "\t";
		PreBiTree(T->lchild);
		PreBiTree(T->rchild);
	}
	return OK;
}

//中序遍历的递归
Status InBiTree(BiTree T)
{
	if (T != NULL)
	{
		InBiTree(T->lchild);
		cout << T->data << "\t";
		InBiTree(T->rchild);
	}
	return OK;
}

//后序遍历的递归
Status LaterBiTree(BiTree T)
{
	if (T != NULL)
	{
		LaterBiTree(T->lchild);
		LaterBiTree(T->rchild);
		cout << T->data << "\t";
	}
	return OK;
}

//先序遍历的非递归
Status SqlpreBiTree(LinkStack& S, BiTree T)
{
	BiTNode* p = T;
	BiTNode* q = new BiTNode;
	while (p || !Empty(S))
	{
		if (p) {
			PushStack(S, p);
			cout << p->data << "\t";
			p = p->lchild;
		}
		else {
			PopStack(S, q);
			p = q->rchild;
		}
	}
	return OK;
}

//中序遍历的非递归
Status SqlInBiTree(LinkStack& S, BiTree T)
{
	BiTNode* p = T;
	BiTNode* q = new BiTNode;
	while (p || !Empty(S))
	{
		if (p) {
			PushStack(S, p);
			p = p->lchild;
		}
		else {
			PopStack(S, q);
			cout << q->data << "\t";
			p = q->rchild;
		}
	}
	return OK;
}


//后序遍历的非递归
Status SqlLaterBiTree(LinkStack& S, BiTree T)
{
	BiTNode* p = T;
	BiTNode* q = new BiTNode;
	BiTNode* e = new BiTNode;
	int flag = 0;
	while (p || !Empty(S))
	{
		while (p) {
			PushStack(S, p);
			p = p->lchild;            //将最左的结点全部压栈
		}
		flag = 1;                   //表示当前结点的左孩子为空或者已经被访问过了
		p = NULL;
		while (flag == 1)
		{
			e = Gettop(S);
			if (e->rchild == p) {
				PopStack(S, q); p = q;
				cout << p->data << "\t";
			}
			else
			{
				p = e->rchild;
				flag = 0;
			}
		}
	}
	return OK;
}

int  main()
{
	cout << "广义表的形式输入(以#结束):";
	BiTree T;
	InitBiTree(T);
	LinkStack S;
	InitStack(S);
	CreateBiTree(T);
	cout << endl;
	cout << "先序遍历的递归输出：";
	PreBiTree(T);
	cout << endl;
	cout << "先序遍历的非递归输出：";
	SqlpreBiTree(S, T);
	cout << endl;
	cout << "中序遍历的递归输出：";
	InBiTree(T);
	cout << endl;
	cout << "中序遍历的非递归输出：";
	SqlInBiTree(S, T);
	cout << endl;
	cout << "后序遍历的递归输出：";
	LaterBiTree(T);
	cout << endl;
	cout << "后序遍历的非递归输出：";
	SqlLaterBiTree(S, T);
	cout << endl;
}




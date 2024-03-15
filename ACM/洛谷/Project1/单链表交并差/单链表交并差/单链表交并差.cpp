#include<iostream>
#include<cstringt.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 30 /* 存储空间初始分配量 */
typedef char ElemType; /* ElemType类型根据实际情况而定 */
/*链表*/
typedef struct PNode {
	char data;
	struct PNode* next;
}PNode, * PLink;

//链表的初始化
int Init(PLink L) {
	if (!L) {
		return 0;
	}
	L->next = NULL;
	return 1;
}
/* 顺序栈结构 */
typedef struct
{
	ElemType data[MAXSIZE];
	int top; /* 用于栈顶指针 */
}SqStack;
/*  构造一个空栈S */
int InitStack(SqStack* S)
{

	S->top = -1;
	return OK;
}
/* 把S置为空栈 */
int ClearStack(SqStack* S)
{
	S->top = -1;
	return OK;
}
/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
int StackEmpty(SqStack S)
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}
/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
ElemType GetTop(SqStack S)
{
	if (S.top == -1)
		return 0;

	return S.data[S.top];
}
/* 插入元素e为新的栈顶元素 */
int Push(SqStack* S, ElemType e)
{
	if (S->top == MAXSIZE - 1) /* 栈满 */
	{
		return ERROR;
	}
	S->top++;				/* 栈顶指针增加一 */
	S->data[S->top] = e;  /* 将新插入元素赋值给栈顶空间 */
	return OK;
}
/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
int Pop(SqStack* S)
{
	if (S->top == -1)
		return ERROR;
	// *e = S->data[S->top];	/* 将要删除的栈顶元素赋值给e */
	S->top--;				/* 栈顶指针减一 */
	return OK;
}
/*******************************************************************************/
/* 顺序栈结构 */
typedef struct
{
	PLink data[MAXSIZE];
	int top; /* 用于栈顶指针 */
}PLinkStack;
int PInitStack(PLinkStack* S)
{
	S->top = -1;
	return OK;
}
/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
int PStackEmpty(PLinkStack S)
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}
/*清空栈*/
int PClearStack(PLinkStack* S)
{
	S->top = -1;
	return OK;
}
/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
PLink PGetTop(PLinkStack S)
{
	if (S.top == -1)
		return 0;
	return S.data[S.top];
}
/* 插入元素e为新的栈顶元素 */
int PPush(PLinkStack* S, PLink e)
{
	if (S->top == MAXSIZE - 1) /* 栈满 */
	{
		return ERROR;
	}
	S->top++;				/* 栈顶指针增加一 */
	S->data[S->top] = e;  /* 将新插入元素赋值给栈顶空间 */
	return OK;
}
/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
int PPop(PLinkStack* S)
{
	if (S->top == -1)
		return ERROR;
	S->top--;				/* 栈顶指针减一 */
	return OK;
}
//输入
void input(PNode* head) {
	PNode* p;
	char t;
	t = 0;
	while (t != '\n')
	{
		if (t >= 32 && t <= 126) {//ASCII可显示字符
			p = (PNode*)malloc(sizeof(PNode));
			p->data = t;
			p->next = head->next;
			head->next = p;
		}
		scanf_s("%c", &t, sizeof('0'));
	}
}
void Swap(PNode* p, PNode* q) {
	PNode temp = *p;
	temp.next = q->next;
	q->next = p->next;
	*p = *q;
	*q = temp;
}
//排序
void Sort(PNode* head) {
	PNode* p, * q, * min;
	if (!head) {
		printf("空集");
		return;
	}
	p = head->next;
	min = p;
	while (p)
	{
		min = p;
		q = p;
		while (q) {
			if (q->data < min->data) {
				min = q;
			}
			q = q->next;
		}
		Swap(p, min);
		p = p->next;
	}
}
//输出操作
void out(PNode* head) {
	Sort(head);
	PNode* p;
	if (!head) {
		printf("空集");
		return;
	}
	p = head->next;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n运算完成\n");
}
//链表的清空
int clearList(PLink L) {
	PLink p, q;
	p = L->next;
	if (p == NULL) {
		return 1;//为空
	}
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}
	L->next = NULL;
	return 1;
}

//集合的并
void And(PLink L1, PLink L2, PLink L3) {
	if (L3->next != NULL)
		clearList(L3);
	PLink p, q, s;
	//对空集的操作
	if (!L1 || !L2) {
		if (!L1) {
			L3 = L2;
		}
		else if (!L2) {
			L3 = L1;
		}
		else {
			L3 = L1;
		}
	}
	//对1号插入3中
	p = L1->next;
	while (p) {
		q = L3->next;
		while (q && (q->data != p->data)) {//C3号中不含有与1号相同的元素
			q = q->next;
		}
		if (q == NULL) {
			s = (PLink)malloc(sizeof(PNode));
			s->data = p->data;
			s->next = L3->next;
			L3->next = s;
		}
		p = p->next;
	}
	//对2号插入3中
	p = L2->next;
	while (p) {
		q = L3->next;
		while (q && (q->data != p->data)) {//C3号中不含有与1号相同的元素
			q = q->next;
		}
		if (q == NULL) {// //当q遍历完一次都没有找到的话，即q的最后为空时就可以将1中的一个元素插入3中
			s = (PLink)malloc(sizeof(PNode));
			s->data = p->data;
			s->next = L3->next;
			L3->next = s;
		}
		p = p->next;
	}
}
//交集
void intersection(PLink L1, PLink L2, PLink L3) {
	if (L3->next != NULL)
		clearList(L3);
	PLink p, q, s, t;
	//1
	p = L1->next;//遍历1
	while (p) {
		q = L2->next;//遍历2
		while (q) {
			if (p->data == q->data)
				break;//找到相同的就返回
			else
				q = q->next;
		}
		if (q) {//查找3号中有没有相同元素
			s = L3->next;
			while (s) {
				if (s->data == p->data)
					break;
				else
					s = s->next;
			}
			if (s == NULL) {
				t = (PLink)malloc(sizeof(PNode));
				t->data = p->data;
				t->next = L3->next;
				L3->next = t;
			}
		}
		p = p->next;
	}
}
//差集
void difference(PLink L1, PLink L2, PLink L3) {
	if (L3->next != NULL)
		clearList(L3);
	PLink p, q, s, t;
	//1
	p = L1->next;//遍历1
	while (p) {
		q = L2->next;
		while (q) {
			if (q->data == p->data)
				break;
			else
				q = q->next;
		}
		if (q == NULL) {//说明2号遍历完了，并且有不一样的
			s = L3->next;
			while (s) {//3号中也没有的话就插入进去
				if (s->data == p->data)
					break;
				else
					s = s->next;
			}
			if (s == NULL) {
				t = (PLink)malloc(sizeof(PNode));
				t->data = p->data;
				t->next = L3->next;
				L3->next = t;
			}
		}
		p = p->next;
	}
}
//运算
PLink choose(PLink A, PLink B, char a) {
	PLink L3;
	L3 = (PNode*)malloc(sizeof(PNode));
	Init(L3);
	switch (a)
	{
	case '+':
		And(A, B, L3);
		break;
	case '-':
		difference(A, B, L3);
		break;
	case '*':
		intersection(A, B, L3);
		break;
	default:
		break;
	}
	return L3;
}
//混合运算
void Mixed(PLink A, PLink B, PLink& L3) {
	SqStack s;//符号栈
	PLinkStack p;//集合栈
	//初始栈
	InitStack(&s);
	PInitStack(&p);
	;//作为中间栈储存链表
	if (L3->next != NULL)
		clearList(L3);
	char str[MAXSIZE];
	printf("请输入运算式：\n");
	scanf_s("%s", str, sizeof(str));
	//printf("输入结束\n%s", str);
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
			if (StackEmpty(s) || GetTop(s) == '(') {
				Push(&s, str[i]);
			}
			else {
				PLink r = PGetTop(p);
				PPop(&p);
				PLink l = PGetTop(p);
				PPop(&p);
				L3 = choose(l, r, GetTop(s));
				PPush(&p, L3);
				Pop(&s);
				Push(&s, str[i]);
			}
			i++;
		}
		else if (str[i] == '(') {
			Push(&s, str[i]);
			i++;
		}
		else if (str[i] == ')') {
			while (GetTop(s) != '(') {
				PLink r = PGetTop(p);
				PPop(&p);
				PLink l = PGetTop(p);
				PPop(&p);
				L3 = choose(l, r, GetTop(s));
				PPush(&p, L3);
				Pop(&s);
			}
			Pop(&s);//让"("出栈
			i++;
		}
		else if (str[i] == 'A') {
			PPush(&p, A);
			i++;
		}
		else if (str[i] == 'B') {
			PPush(&p, B);
			i++;
		}
	}
	while (!StackEmpty(s))//符号栈不为空
	{
		PLink r = PGetTop(p);
		PPop(&p);
		PLink l = PGetTop(p);
		PPop(&p);
		L3 = choose(l, r, GetTop(s));
		PPush(&p, L3);
		Pop(&s);
	}
	PClearStack(&p);
	ClearStack(&s);
}


int main() {
	PLink L1, L2, L3;
	L1 = (PLink)malloc(sizeof(PNode));
	L2 = (PLink)malloc(sizeof(PNode));
	L3 = (PLink)malloc(sizeof(PNode));
	Init(L1);
	Init(L2);
	Init(L3);
	printf("请输入集合Set1  ");
	input(L1);
	printf("请输入集合Set2  ");
	input(L2);
	
	int flag = 1;
	while (flag)
	{
		printf("请选择\n");
		printf("0----退出程序\n1---并集运算\n2---交集运算\n3---差集运算\n4---混合运算\n");
		char x;
		x = getchar();
		while (isspace(x))
			x = getchar();
		switch (x) {
		case '0':
			flag = 0;
			break;
		case '1':
			And(L1, L2, L3);
			printf("并集是：");
			out(L3);
			break;
		case '2':
			intersection(L1, L2, L3);
			printf("交集是：");
			out(L3);
			break;
		case '3':
			difference(L1, L2, L3);
			printf("(A-B)差集是：");
			out(L3);
			printf("(B-A)差集是：");
			difference(L2, L1, L3);
			out(L3);
			break;
		case '4':
			Mixed(L1, L2, L3);
			out(L3);
			break;
		}
	}
	return 0;
}


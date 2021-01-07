#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define N 6					//最大停车数
#define M 4					//最大候车数
#define Price 2				//停车费
typedef struct
{
	int CN[N];			//车牌号
	int CT[N];			//进场时间
	int top;            //顺序表
} SqStack;
typedef struct
{
	int CN[M];			//车牌号
	int front, rear;	    // 队列
} SqQueue;

/*********************************************栈的运算算法**************************************************/
void InitStack(SqStack*& s)	 //初始化
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
bool StackEmpty(SqStack* s)	//判空，空返回1
{
	return(s->top == -1);
}
bool StackFull(SqStack* s)	//判满
{
	return(s->top == N - 1);
}
bool Push(SqStack*& s, int e1, int e2)  //压入~
{
	if (s->top == N - 1)
		return false;
	s->top++;
	s->CN[s->top] = e1;
	s->CT[s->top] = e2;
	return true;
}
bool Pop(SqStack*& s, int& e1, int& e2)  //弹出~
{
	if (s->top == -1)
		return false;
	e1 = s->CN[s->top];
	e2 = s->CT[s->top];
	s->top--;
	return true;
}
void DispStack(SqStack* s)	 //遍历输出
{
	for (int i = s->top; i >= 0; i--)
		printf("%d ", s->CN[i]);
	printf("\n");
}

/********************************************队列的运算算法**************************************************/
void InitQueue(SqQueue*& q)		//初始化
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
bool QueueEmpty(SqQueue* q)		//判空，空返回1
{
	return(q->front == q->rear);
}
bool QueueFull(SqQueue* q)			//判满
{
	return ((q->rear + 1) % M == q->front);
}
bool enQueue(SqQueue*& q, int e)		//压入
{
	if ((q->rear + 1) % M == q->front)	//队满，返回false，退出
		return false;
	q->rear = (q->rear + 1) % M;
	q->CN[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, int& e)	//弹出
{
	if (q->front == q->rear)			//队空的情况
		return false;
	q->front = (q->front + 1) % M;
	e = q->CN[q->front];
	return true;
}
void DispQueue(SqQueue* q)	 //遍历输出
{
	int i = (q->front + 1) % M;
	printf("%d ", q->CN[i]);
	while ((q->rear - i + M) % M > 0)
	{
		i = (i + 1) % M;
		printf("%d ", q->CN[i]);
	}
	printf("\n");
}
int main()
{
	int x, i, j;
	int n, e1, t, e2;
	SqStack* pk, * st;
	SqQueue* Qu;
	InitStack(pk);
	InitStack(st);
	InitQueue(Qu);
	while (x != 0)
	{
		printf(" 0****退出\n 1****到达\n 2****离开\n 3****停车情况\n 4****候车情况\n ");
		scanf_s("%d", &x);
		switch (x)
		{
		case 1:		//到达
			printf("  车号 到达时间:");
			scanf_s("%d%d", &n, &t);
			if (!StackFull(pk))
			{
				Push(pk, n, t);//如果不满，压入队列
				printf("  停车场位置:%d\n", pk->top + 1);
			}
			else						//停车场满
			{
				if (!QueueFull(Qu))		//候车场不满
				{
					enQueue(Qu, n);
					printf("  候车场位置:%d\n", Qu->rear);
				}
				else
					printf("  候车场已满\n");
			}
			break;
		case 2:		//离开
			printf("  车牌号 离开时间:");
			scanf_s("%d%d", &n, &t);
			for (i = 0; i <= pk->top && pk->CN[i] != n; i++);
			if (i > pk->top)
				printf("  没有这辆车\n");
			else
			{
				for (j = i; j <= pk->top; j++)
				{
					Pop(pk, e1, e2);
					Push(st, e1, e2);	//从pk取出，放入st中
				}
				Pop(pk, e1, e2);				//该汽车离开
				printf("  %d停车费总计:%d\n", n, (t - e2) * Price);
				while (!StackEmpty(st))
				{
					Pop(st, e1, e2);
					Push(pk, e1, e2);	//将st放回pk
				}
				if (!QueueEmpty(Qu))		//队不空时,将队头进栈pk
				{
					deQueue(Qu, e1);
					Push(pk, e1, t);		//以当前时间开始计费
				}
			}
			break;
		case 3:		//输出停车场情况
			if (!StackEmpty(pk))//有车
			{
				printf("  停车场中的车辆:\n");
				DispStack(pk);//输出停车场中的车辆车牌号
			}
			else
				printf("  无车，可以停车！\n");
			break;
		case 4:		//输出候车场情况
			if (!QueueEmpty(Qu))//有车
			{
				printf("  候车场中的车辆:\n");
				DispQueue(Qu);//输出候车场中的车辆车牌号
			}
			else
				printf("  候车场中无车辆\n");
			break;
		case 0:		//退出
			break;
		default:
			printf("  检查输入！\n");
			break;
		}
	}
	return 1;
}

#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;		//队首和队尾指针
} SqQueue;
typedef struct
{
    ElemType data[MaxSize];
    int top;				//栈指针
} SqStack;

void InitQueue(SqQueue*& q)
{
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}
void InitStack(SqStack*& s)   //初始化顺序栈
{
    s = (SqStack*)malloc(sizeof(SqStack));
    s->top = -1;
}

void DestroyQueue(SqQueue*& q)
{
    free(q);
}
bool StackEmpty(SqStack* s)		//判断栈空否
{
    return(s->top == -1);
}

bool QueueEmpty(SqQueue* q)
{
    return(q->front == q->rear);
}
bool enQueue(SqQueue*& q, ElemType e)//入队列
{
    if ((q->rear + 1) % MaxSize == q->front)	//队满上溢出
        return false;
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}
bool deQueue(SqQueue*& q, ElemType& e)//出队列
{
    if (q->front == q->rear)		//队空下溢出
        return false;
    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}
bool Push(SqStack*& s, ElemType e)	 //进栈
{
    if (s->top == MaxSize - 1)    //栈满的情况，即栈上溢出
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}
bool Pop(SqStack*& s, ElemType& e)	 //出栈
{
    if (s->top == -1)		//栈为空的情况，即栈下溢出
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}
void DestroyStack(SqStack*& s) //销毁顺序栈
{
    free(s);
}

void Reverse(SqQueue*& qu)
{
    ElemType e;
    SqStack* st;
    InitStack(st);
    while (!QueueEmpty(qu))
    {
        deQueue(qu, e);
        Push(st,e);
    }
    InitQueue(qu);
    while (!StackEmpty(st))
    {
        Pop(st, e);
        enQueue(qu, e);
    }
}
void number(int n)
{
    int i;
    ElemType e;
    SqQueue* q;
    InitQueue(q);
    for (i = 1; i <= n; i++)
        enQueue(q, i);
    
    printf("报数序列：");
    while (!QueueEmpty(q))
    {
        deQueue(q, e);
        printf("%d ", e); 
    }
    printf("\n");
    DestroyQueue(q);
}
void num_rev()
{
    int i;
    bool b = true;
    ElemType e;
    SqQueue* q;
    InitQueue(q);
    printf("请输入一串数,-1以结束，空格隔开, :");
    while (b == true) {
        // 1 2 9 0 8 22 56 5 75 -1
        scanf_s("%d", &i);      
        
        if (i != -1)
            enQueue(q, i);
        else
            b = false;
    }
    Reverse(q);
    printf("逆序数列：");
    while (!QueueEmpty(q))
    {
        deQueue(q, e);
        printf("%d ", e);
    }
    DestroyQueue(q);
}

int main()
{
    int i, n = 10;
    printf("初始序列：");
    for (i = 1; i <= n; i++)
        printf("%d ", i);
    printf("\n");
    number(n);
    num_rev();
}






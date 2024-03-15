#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define elem int
int vis[100];
typedef struct queue {
    elem *data;
    int front;
    int rear;
    int max_size;
}pqueue;

void init_queue(pqueue *q, int max_size)
{
    q->front = q->rear = 0;
    q->data = (elem*)malloc(max_size * sizeof(elem));
}
int full_queue(pqueue *q)
{
    return (q->front == (q->rear + 1) % q->max_size) ? 1 : 0;
}

int empty_queue(pqueue *q)
{
    return (q->front == q->rear) ? 1 : 0;
}

int enqueue(pqueue *q, int val)
{
    if (full_queue(q))
        return 0;
    else
    {
        q->data[q->rear] = val;
        q->rear = (q->rear + 1) % q->max_size;
    }
    return 1;
}

int dequeue(pqueue *q)
{
    if (empty_queue(q))
        return 0;
    else
        q->front = (q->front + 1) % q->max_size;
    return 1;
}
void into_queue(pqueue *q)
{
    if (empty_queue(q)) {
        printf("queue is empty\n");
        return;
    }
    else {
        for (int i = q->front; i < q->rear; i++) {
            vis[i] = q->data[i];
        }
    }
    return;
}
int main()
{
    int n, m, len;
    scanf_s("%d%d", &n, &m);
    queue Q;
    len = n;
    init_queue(&Q, n);
    for (int i = 1; i <= n; i++)
        enqueue(&Q, i);
    into_queue(&Q);
    int j = 1;
    while (!empty_queue(&Q)||len !=0)
    {
        if (j % m == 0) {
            printf("%d ", vis[j - 1]);
            dequeue(&Q);
            len--;
        }
        else {
            dequeue(&Q);
            enqueue(&Q, vis[j - 1]);
            into_queue(&Q);
        }
        j++;
    }
}



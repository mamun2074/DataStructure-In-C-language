#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void Create(struct Queue *q)
{
    printf("Enter your que size \n");
    scanf("%d", &q->size);
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void Enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full \n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int Dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is Emplty \n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    if (q.front == q.rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        
        printf("Dispaly \n");
        while ((q.front + 1) % q.size != (q.rear+1) % q.size)
        {
            printf("%d ", q.Q[(q.front + 1) % q.size]);
            q.front = (q.front + 1) % q.size;
        }
        printf("\n");
    }
}

int main()
{
    struct Queue q;
    Create(&q);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 100);

    Display(q);

    printf("%d \n", Dequeue(&q));
    printf("%d \n", Dequeue(&q));
    printf("%d \n", Dequeue(&q));
    Display(q);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *q;
};

void enqueue(struct Queue *que, int x)
{
    if (que->rear == que->size - 1)
    {
        printf("Queue is full \n");
    }
    else
    {
        que->rear++;
        que->q[que->rear] = x;
    }
}

int dequeue(struct Queue *que)
{
    int x = -1;
    if (que->front == que->rear)
    {
        printf("Queue is empty \n");
    }
    else
    {
        que->front++;
        x = que->q[que->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i;
    for (i = q.front+1; i <= q.rear; i++)
    {
        printf("%d ", q.q[i]);
    }
    printf("\n");
}

void create(struct Queue *que)
{
    que->front = -1;
    que->rear = -1;
    printf("Please enter size of queue \n");
    scanf("%d", &que->size);
    que->q = (int *)malloc(que->size * sizeof(int));
}

int main()
{
    struct Queue que;

    create(&que);
    enqueue(&que, 10);
    enqueue(&que, 20);
    enqueue(&que, 30);
    enqueue(&que, 40);

    printf("First deque is %d\n", dequeue(&que));

    display(que);

    return 0;
}
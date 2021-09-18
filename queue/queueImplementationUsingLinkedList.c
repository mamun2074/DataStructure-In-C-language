#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * front, *rear = NULL;

struct Node *CreateNode(int x)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    // check heap is full
    if (p == NULL)
    {
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void Enqueue(int x)
{
    struct Node *temp;
    temp = CreateNode(x);
    if (temp)
    {
        if (front == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    else
    {
        printf("Heap is full \n");
    }
}

int Dequeue()
{
    int x = -1;
    if (front)
    {
        x = front->data;
        front = front->next;
    }
    return x;
}

void Display()
{
    struct Node *temp;
    temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(50);
    printf("Dequeue item data is: %d \n", Dequeue());
    Display();
    
    printf("Dequeue item data is: %d \n", Dequeue());
    Display();


    return 0;
}
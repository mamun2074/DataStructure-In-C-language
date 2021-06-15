#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int x)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        /* code */
        printf("Data is: %d \n", p->data);
        p = p->next;
    }
}


int main()
{
    struct Node *head, *temp, *tail;
    int n, x, i;

    printf("How many data want to insert \n");
    scanf("%d", &n);

    printf("Enter all data\n");
    scanf("%d", &x);
    head = createNode(x);
    tail = head;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &x);
        temp = createNode(x);
        tail->next = temp;
        tail = temp;
    }

    display(head);

    return 0;
}
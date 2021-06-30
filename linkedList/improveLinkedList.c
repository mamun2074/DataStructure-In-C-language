#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} * head, *tail, *temp = NULL;

struct Node *createNode(int x)
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void insertNodeToLast(struct Node *newNode)
{
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *newNode, *test;
    int x, i, non;
    test = head;
    printf("Enter Number Of Node \n");
    scanf("%d", &non);
    printf("Enter all node value \n");
    for (i = 0; i < non; i++)
    {
        scanf("%d", &x);
        insertNodeToLast(createNode(x));
    }

    display();

    insertNodeToLast(createNode(400));
    display();

    return 0;
}
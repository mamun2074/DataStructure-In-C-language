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
void insertNodeToFirst(struct Node *newNode)
{
    if (head != NULL)
    {
        newNode->next = head;
        head = newNode;
    }
}

int isSortedNode()
{
    struct Node *currentNode;
    currentNode = head;
    int data = -32768;
    while (currentNode != NULL)
    {
        if (data < currentNode->data)
        {
            data = currentNode->data;
        }
        else
        {
            return 0;
        }
        currentNode = currentNode->next;
    }

    return 1;
}

void insertNodeIntoSortedNode(struct Node *newNode)
{
    struct Node *currentNode, *prevNode;
    prevNode = currentNode = head;
    if (currentNode != NULL && newNode->data < currentNode->data)
    {
        newNode->next = head->next;
        head = newNode;
    }
    else
    {

        while (currentNode != NULL)
        {
            if (currentNode->data >= newNode->data)
            {
                newNode->next = prevNode->next;
                prevNode->next = newNode;
                break;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
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

    //insertNodeToFirst(createNode(400));

    //printf("%d \n", isSortedNode());

    insertNodeIntoSortedNode(createNode(30));
    insertNodeIntoSortedNode(createNode(30));

    display();

    return 0;
}
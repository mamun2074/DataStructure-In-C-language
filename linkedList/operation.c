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

void insertNodeEndIntoLinkedList(struct Node *newNode)
{
    struct Node *fn;
    fn = temp = head;
    while (temp != NULL)
    {
        fn = temp;
        temp = temp->next;
    }

    if (fn == NULL)
    {
        head = newNode;
    }
    else
    {
        fn->next = newNode;
    }
}

void insertNode(struct Node *newNode, int pos)
{
    temp = head;
    int i;
    if (pos == 0 && head != NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else if (pos > 0 && head != NULL)
    {
        for (i = 0; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else if (head == NULL)
    {
        head = newNode;
    }
}

int nodePop()
{
    int data = 0;
    struct Node *currentNode, *nextNode;
    currentNode = nextNode = temp = head;
    if (head == NULL)
    {
        return data;
    }
    else
    {
        while (temp != NULL)
        {
            currentNode = temp;
            nextNode = currentNode->next;
            if (nextNode->next == NULL)
            {
                break;
            }
            temp = nextNode;
        }
        data = nextNode->data;
        currentNode->next = NULL;
    }
    return data;
}

void displayLinkList(struct Node *p)
{
    while (p != NULL)
    {
        if (p->next)
        {
            printf("%d, ", p->data);
        }
        else
        {
            printf("%d", p->data);
        }
        p = p->next;
    }
    printf(" \n");
}

int main()
{
    struct Node *p, *temp, *tail;
    int non, i, x;
    printf("Number Of Node \n");
    scanf("%d", &non);
    printf("Enter node values \n");

    for (i = 0; i < non; i++)
    {
        scanf("%d", &x);
        insertNode(createNode(x), i);
    }
    //displayLinkList(head);

    //insertNode(createNode(400), i);

    printf("%d \n", nodePop(head));

    //printf("%d \n", nodePop());
    displayLinkList(head);
    printf("%d \n", nodePop(head));
    displayLinkList(head);

    return 0;
}
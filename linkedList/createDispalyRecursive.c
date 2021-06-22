#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int x)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node *));
    p->data = x;
    p->next = NULL;
    return p;
}
void displayRecursive(struct Node *p)
{
    if (p != NULL)
    {
        /* code */
        printf("%d ", p->data);
        displayRecursive(p->next);
    }
}

void displayRecursiveDesc(struct Node *p)
{
    if (p != NULL)
    {
        /* code */
        displayRecursiveDesc(p->next);
        printf("%d ", p->data);
    }
}

int countingNode(struct Node *p)
{
    int nn = 0;
    while (p != NULL)
    {
        /* code */
        nn++;
        p = p->next;
    }
    return nn;
}
int sumOfNodeValue(struct Node *p)
{
    int total = 0;
    while (p != NULL)
    {
        /* code */
        total += p->data;
        p = p->next;
    }
    return total;
}

int countingNodeRecursive(struct Node *p)
{
    if (p == 0)
    {
        /* code */
        return 0;
    }
    else
    {
        return countingNodeRecursive(p->next) + 1;
    }
}
int sumOfNodeValuesRecursive(struct Node *p)
{
    if (p == NULL)
    {
        /* code */
        return 0;
    }
    else
    {
        return sumOfNodeValuesRecursive(p->next) + p->data;
    }
}

int findMax(struct Node *p)
{
    int min = -327645;
    while (p)
    {
        /* code */
        if (p->data > min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}
int findMaxRecursive(struct Node *p)
{
    int x = 0;
    if (p == NULL)
    {
        return -327645;
    }
    else
    {
        x = findMaxRecursive(p->next);
        return (x > p->data) ? x : p->data;
    }
}

struct Node *SearchNode(struct Node *p, int x)
{
    while (p != NULL)
    {
        /* code */
        if (p->data == x)
        {
            /* code */
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void insertNewNode(struct Node *p, int pos, int data)
{
    struct Node *temp, *newNode;
    int i;
    temp = p;
    newNode = createNode(data);
    if (pos == 0)
    {
        /* code */
        newNode->next = temp;
        temp = newNode;
    }
    else if (pos > 0)
    {
        for (i = 0; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }
        if (temp)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

int main()
{
    struct Node *head, *tail, *temp;
    int i, x, n, data;
    printf("Number of nodes\n");
    scanf("%d", &n);

    printf("Enter node values\n");
    scanf("%d", &x);

    head = tail = createNode(x);
    for (i = 1; i < n; i++)
    {
        /* code */
        scanf("%d", &x);
        temp = createNode(x);
        tail->next = temp;
        tail = temp;
    }

    displayRecursive(head);
    //printf("\nNumber of nodes: %d \n", countingNode(head));
    //printf("\nNumber of nodes Recursive: %d \n", countingNodeRecursive(head));
    //printf("\nTotal sum: %d\n", sumOfNodeValue(head));
    //printf("\nTotal sum recursive: %d\n", sumOfNodeValuesRecursive(head));

    //printf("\nFind max: %d", findMax(head));

    //printf("\nFind max: %d", findMaxRecursive(head));

    // printf("Enter searching element \n");
    // scanf("%d", &data);

    // temp = SearchNode(head, data);

    // if (temp)
    // {
    //     /* code */
    //     printf("Searching data is: %d\n", temp->data);
    // }
    // else
    // {
    //     printf("Not found\n");
    // }

    insertNewNode(head, 0, 800);

    printf("\n");

    displayRecursive(head);

    return 0;
}
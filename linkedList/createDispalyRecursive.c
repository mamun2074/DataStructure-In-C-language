#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    struct Node *head, *tail, *temp;
    int i, x, n;
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
    printf("\nNumber of nodes: %d \n", countingNode(head));
    printf("\nNumber of nodes Recursive: %d \n", countingNodeRecursive(head));
    printf("\nTotal sum: %d\n", sumOfNodeValue(head));
    printf("\nTotal sum recursive: %d\n", sumOfNodeValuesRecursive(head));

    return 0;
}
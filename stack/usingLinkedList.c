#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
} *top = NULL;

struct stack *createStack(int x)
{
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = x;
    temp->next = NULL;
    return temp;
}
int isEmpty()
{
    int x = -1;
    if (top == NULL)
    {
        x = 1;
    }
    return x;
}

void stackPush(struct stack *temp)
{
    if (isEmpty() == 1) // insert first node
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}
int stackTop()
{
    int x = -1;
    if (isEmpty() == 1)
    {
        return x;
    }
    else
    {
        x = top->data;
    }
    return x;
}

int stackPeek(int position)
{
    struct stack *temp;
    temp = top;
    int x = -1, i;
    if (position > 0)
    {
        for (i = 0; temp != NULL && i < position - 1; i++)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            x = temp->data;
        }
    }

    return x;
}

int main()
{

    struct stack *temp;

    temp = createStack(10);
    stackPush(temp);

    temp = createStack(20);
    stackPush(temp);

    temp = createStack(30);
    stackPush(temp);

    temp = createStack(40);
    stackPush(temp);


    printf("Top is :  %d \n", stackTop());
    printf("Peck data is :  %d \n", stackPeek(4));

    return 0;
}
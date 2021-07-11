#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int stackSize;
    int top;
    int *s;
};

struct stack *createStack(int size)
{
    struct stack *initStack;
    initStack = (struct stack *)malloc(sizeof(struct stack));

    initStack->stackSize = size;
    initStack->top = -1;
    initStack->s = (int *)malloc(initStack->stackSize * sizeof(int));
    return initStack;
}

int isFull(struct stack p)
{
    int x = -1;
    if (p.top == p.stackSize - 1)
    {
        x = 1;
    }
    return x;
}

int isEmpty(struct stack p)
{
    int x = -1;
    if (p.top == -1)
    {
        x = 1;
    }
    return x;
}

void stackPush(struct stack *p, int x)
{
    if (isFull(*p) == -1)
    {
        p->top++;
        p->s[p->top] = x;
    }
    else
    {
        printf("Stack is overflow \n");
    }
}

int stackPop(struct stack *p)
{
    int x = -1;
    if (isEmpty(*p) == -1)
    {
        x = p->s[p->top--];
    }
    return x;
}

int stackPeek(struct stack p, int positiion)
{
    int x = -1;
    // position getter than top+1 then stack data is not found
    if (positiion > (p.top + 1))
    {
        return x;
    }

    if (isEmpty(p) == -1)
    {
        // index = top-position+1;
        x = p.s[p.top - positiion + 1];
    }
    return x;
}

int stackTop(struct stack p)
{
    int x = -1;
    if (isEmpty(p) == -1)
    {
        x = p.s[p.top];
    }
    return x;
}

int main()
{
    struct stack *mainStack;
    int Size, item, i;

    printf("Enter stack size \n");
    scanf("%d", &Size);
    mainStack = createStack(Size);

    printf("Enter stack data items \n");
    for (i = 0; i < Size; i++)
    {
        scanf("%d", &item);
        stackPush(mainStack, item);
    }

    // stack pop means delete item on top
    stackPop(mainStack);

    printf("%d \n", stackTop(*mainStack));
    printf("%d \n", stackPeek(*mainStack, 2));

    return 0;
}
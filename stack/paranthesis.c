#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bracket
{
    char *paranthasis;
    int stack_size;
    int top;
};

// Create initial Stack for paranthasis
void createStack(struct bracket *b)
{
    int size;
    printf("Enter size of string \n");
    scanf("%d", &size);
    b->stack_size=size;
    b->paranthasis= (char *)malloc(size*sizeof(char));
    b->top=-1;
}
// Insert bracket to stack
void pushStack(struct bracket *b, char br)
{
    b->paranthasis[b->top++]=br;
}
// Delete top item from stack
void popStack(struct bracket *b)
{
    b->paranthasis[b->top--];
}
// sorted only () and sent to push and pop function
void insertBracket(struct bracket *b, char br[500], int stringSize)
{
    int i;
    for ( i = 0; i < stringSize; i++)
    {
        if (br[i] =='(')
        {
            pushStack(b, br[i]);
        }
        if (br[i]==')')
        {
            popStack(b);
        }
    }
}
// Check if bracket balance and unbalanced
void checkBalance(struct bracket *b)
{
    if (b->top ==-1)
    {
        printf("Brack is balanced\n");
    }else{
        printf("Non Balanced \n");
    }
}

int main()
{
    struct bracket b;
    char br[500];
    int stringSize;
    createStack(&b);
    strcpy(br, "(abc)+((c))");
    stringSize=11;

    insertBracket(&b, br, stringSize);

    checkBalance(&b);


    return 0;
}
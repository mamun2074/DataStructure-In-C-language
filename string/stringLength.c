#include <stdio.h>
#include <stdlib.h>

// finding string length
int stringLength(char welcome[])
{
    int i;
    for (i = 0; welcome[i] != '\0'; i++)
    {
    }
    return i;
}

// changing letter case
void ChangingCase(char welcome[])
{
    int i;
    for (i = 0; welcome[i] != '\0'; i++)
    {
        if (welcome[i] >= 'A' && welcome[i] <= 'Z')
        {
            welcome[i] = welcome[i] + 32;
        }
        else if (welcome[i] >= 'a' && welcome[i] <= 'z')
        {
            welcome[i] = welcome[i] - 32;
        }
    }
}

int main()
{

    char welcome[500];
    gets(welcome);
    ChangingCase(welcome);

    printf("%s", welcome);

    return 0;
}
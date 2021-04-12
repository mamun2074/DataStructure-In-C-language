#include <stdio.h>

char *ReverseOneMethod(char a[])
{
    char *b;
    int i, j;
    for (i = 0; a[i] != '\0'; i++)
    {
    }

    i = i - 1;
    for (j = 0; i >= 0; j++, i--)
    {
        b[j] = a[i];
    }

    b[j] = '\0';

    return b;
}

void ReverseTwoMethod(char a[])
{
    int i, j;
    char temp;
    for (j = 0; a[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
}

int main()
{
    char a[] = "Python";
    char *b;
    //b = ReverseOneMethod(a);

    ReverseTwoMethod(a);

    printf("%s", a);

    return 0;
}
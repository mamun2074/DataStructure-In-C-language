#include <stdio.h>

int diagonal[5];

void set(int row, int colomn, int x)
{
    if (row == colomn)
    {
        diagonal[row - 1] = x;
    }
}
int get(int row, int colomn)
{
    if (row == colomn)
    {
        return diagonal[row - 1];
    }
    else
        return 0;
}

int main()
{
    set(1, 1, 5);
    set(2, 2, 6);
    set(3, 3, 7);
    printf("%d", get(2,2));

    return 0;
}
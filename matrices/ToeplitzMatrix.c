#include <stdio.h>
#include <stdlib.h>
struct matrix
{
    int *A;
    int n;
};

void setToeplizMatrix(struct matrix *m, int i, int j, int x)
{
    if (i <= j) // Upper triangular
    {
        m->A[j - i] = x;
    }
    else if (i > j) // lower triangular
    {
        m->A[m->n + i - j - 1] = x;
    }
}
void display(struct matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i <= j)
            {
                printf("%d ", m.A[j - i]);
            }
            else
            {
                printf("%d ", m.A[m.n + i - j - 1]);
            }
        }
        printf("\n");
    }
}

int main()
{

    struct matrix m;
    int i, j, x;
    printf("Enter matrix size \n");
    scanf("%d", &m.n);
    m.A = (int *)malloc(3 * m.n - 2 * sizeof(int));
    printf("Enter all element \n");
    for (i = 1; i <= m.n; i++)
    {
        /* code */
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            setToeplizMatrix(&m, i, j, x);
        }
    }
    printf("\n\n");
    display(m);

    return 0;
}
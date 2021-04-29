#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int *A;
    int n;
};

void setTridiagonalMatrix(struct matrix *m, int i, int j, int x)
{
    if (i - j == 1) // lower diagonal
    {
        // any index i-2;
        m->A[i - 2] = x;
    }
    else if (i - j == 0) // Main diagonal
    {
        // any index (n-1)+(i-1)
        m->A[(m->n - 1) + (i - 1)] = x;
    }
    else if (i - j == -1) // Upper diagonal
    {
        /* any index (n-1)+ n + (i-1)
        /* 2n+i-2
        */
        m->A[(m->n - 1) + m->n + (i - 1)] = x;
    }
}

void display(struct matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i - j == 1) // lower diagonal
            {
                printf("%d ", m.A[i - 2]);
            }
            else if (i - j == 0) // main diagonal
            {
                printf("%d ", m.A[m.n - 1 + i - 1]);
            }
            else if (i - j == -1) // Upper diagonal
            {
                printf("%d ", m.A[m.n - 1 + m.n + i - 1]);
            }
            else
            {
                printf("0 ");
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
            setTridiagonalMatrix(&m, i, j, x);
        }
    }
    printf("\n \n");
    display(m);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct triangular
{
    int *A;
    int n;
};

void setRowMajonUpperTriangular(struct triangular *t, int i, int j, int x)
{
    int index;
    if (i <= j)
    {
        index = (t->n * (i - 1)) - ((i - 2) * (i - 1) / 2) + (j - i);
        t->A[index] = x;
    }
}

void display(struct triangular t)
{
    int i, j, index;
    for (i = 1; i <= t.n; i++)
    {
        for (j = 1; j <= t.n; j++)
        {
            if (i > j)
            {
                printf("0 ");
            }
            else
            {
                index = (t.n * (i - 1)) - ((i - 2) * (i - 1) / 2) + (j - i);
                printf("%d ", t.A[index]);
            }
        }
        printf("\n");
    }
}

int main()
{

    int i, j, x;
    struct triangular m;
    printf("Enter dimension \n");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    printf("Enter all matrix element \n");

    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            if (i <= j)
            {
                setRowMajonUpperTriangular(&m, i, j, x);
            }
        }
    }

    printf("\n \n");
    display(m);

    return 0;
}
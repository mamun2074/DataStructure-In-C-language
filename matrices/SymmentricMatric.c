#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int *A;
    int n;
};

void setLowerTriangularMatrixRowMajor(struct matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        /* code */
        m->A[((i * (i - 1) / 2) + (j - 1))] = x;
    }
}

void display(struct matrix m)
{
    int i, j, index;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
            {
                index = ((i * (i - 1) / 2) + (j - 1));
                printf("%d ", m.A[index]);
            }
            else
            {
                index = (j * (j - 1) / 2) + (i - 1);
                printf("%d ", m.A[index]);
            }
        }
        printf("\n");
    }
}

int main()
{

    struct matrix m;
    int i, j, x;
    printf("Enter your matrix length \n");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    printf("Enter your matrix element \n");

    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            if (i >= j)
            {
                setLowerTriangularMatrixRowMajor(&m, i, j, x);
            }
        }
    }

    printf("\n\n");
    display(m);

    return 0;
}
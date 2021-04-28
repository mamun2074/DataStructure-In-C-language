#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int *A;
    int n;
};

void setLowerTriangularRowMajor(struct matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[i * (i - 1) / 2 + (j - 1)] = x;
    }
}

int getLowerTriangularRowMajor(struct matrix lower, int i, int j)
{
    if (i >= j)
    {
        return lower.A[(i * (i - 1)) / 2 + (j - 1)];
    }
    else
    {
        return 0;
    }
}

void display(struct matrix a)
{
    int i, j;
    for (i = 1; i <= a.n; i++)
    {
        for (j = 1; j <= a.n; j++)
        {
            if (i >= j)
            {
                printf("%d ", a.A[i * (i - 1) / 2 + j - 1]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void setColomnMajorLowerTriangularMatrix(struct matrix *m, int i, int j, int x)
{
    if (i >= j) // lower tringular matrx
    {
        /* Rule of colomn major lower Matrix
        /* [n+n-1+n-2+ ........n-(j-2)] + (i-j)
        /* n(j-1)-[1+2+3+.....j-2] + (i-j)
        /* n(j-1)-[(j-2)] + (i-j)
        */
        int index = ((m->n * (j - 1)) - ((j - 2) * (j - 1) / 2)) + (i - j);
        m->A[index] = x;
    }
}

int getColomnMajonLowerTriangularMatrix(struct matrix m, int i, int j)
{
    if (i >= j) // lower tringular matrx
    {
        /* Rule of colomn major lower Matrix
        /* [n+n-1+n-2+ ........n-(j-2)] + (i-j)
        /* n(j-1)-[1+2+3+.....j-2] + (i-j)
        /* n(j-1)-[(j-2)] + (i-j)
        */
        int index = ((m.n * (j - 1)) - ((j - 2) * (j - 1) / 2)) + (i - j);
        return m.A[index];
    }
}

int main()
{

    int i, j, x;
    struct matrix m;
    printf("Enter dimension \n");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    printf("Enter all matrix element \n");

    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            // setLowerTriangularRowMajor(&m, i, j, x);
             setColomnMajorLowerTriangularMatrix(&m, i, j, x);
        }
    }

    printf("\n\n");
    display(m);

    return 0;
}
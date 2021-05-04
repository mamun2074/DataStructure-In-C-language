#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int row;
    int col;
    int el;
};

struct Sparce
{
    int m;
    int n;
    int nonZeroElement;
    struct Element *el;
};

void Create(struct Sparce *s)
{
    int i;
    printf("Enter matrix size \n");
    scanf("%d%d", &s->m, &s->n);
    printf("Number of non-zero element \n");
    scanf("%d", &s->nonZeroElement);
    // size of element
    s->el = (struct Element *)malloc(s->nonZeroElement * sizeof(struct Element));
    printf("Enter your non-zero items \n");
    for (i = 0; i < s->nonZeroElement; i++)
    {
        scanf("%d%d%d", &s->el[i].row, &s->el[i].col, &s->el[i].el);
    }
    printf("\n\n");
}

void Display(struct Sparce s)
{
    /*
    / i=matrix row, j=matrix colomn, k= array element flag
    */
    int i, j, k = 0;
    for (i = 1; i <= s.m; i++)
    {
        for (j = 1; j <= s.n; j++)
        {
            if (i == s.el[k].row && j == s.el[k].col)
            {
                printf("%d ", s.el[k++].el);
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
    struct Sparce s;
    Create(&s);
    Display(s);
    return 0;
}
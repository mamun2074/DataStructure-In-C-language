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

struct Sparce *Add(struct Sparce s1, struct Sparce s2)
{
    struct Sparce *result;
    int i, j, k;
    i = j = k = 0;
    if (s1.m != s2.m || s1.n != s2.n)
    {
        return 0;
    }
    result = (struct Sparce *)malloc(sizeof(struct Sparce));
    result->el = (struct Element *)malloc((s1.nonZeroElement + s2.nonZeroElement) * sizeof(struct Element));
    while (i < s1.nonZeroElement && j < s2.nonZeroElement)
    {
        if (s1.el[i].row < s2.el[j].row) // s1 row is smaller
        {
            result->el[k++] = s1.el[i++];
        }
        else if (s1.el[i].row > s2.el[j].row) // s1 row is getter
        {
            result->el[k++] = s2.el[j++];
        }
        else // all row are equal
        {
            if (s1.el[i].col < s2.el[j].col) // s1 colomn is smaller
            {
                result->el[k++] = s1.el[i++];
            }
            else if (s1.el[i].col > s2.el[j].col) // s1 colomn is getter
            {
                result->el[k++] = s2.el[j++];
            }
            else
            { // all row and colomn are equal. So, s1 + s2 element
                result->el[k] = s1.el[i];
                result->el[k++].el = s1.el[i++].el + s2.el[j++].el;
            }
        }
    }
    // remaining i
    for (; i < s1.nonZeroElement; i++)
    {
        result->el[k++] = s1.el[i];
    }
    // remaining j
    for (; j < s2.nonZeroElement; j++)
    {
        result->el[k++] = s2.el[j];
    }
    // now result of m and n
    result->m = s1.m;
    result->n = s1.n;
    return result;
}

int main()
{
    struct Sparce s1, s2, *result;
    Create(&s1);
    Create(&s2);
    result = Add(s1, s2);

    printf("First Matrix \n");
    Display(s1);
    printf("Second Matrix \n");
    Display(s2);
    printf("Result Matrix \n");
    Display(*result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct tarm
{
    int coefficient;
    int exponent;
};
struct polynomial
{
    int n;
    struct tarm *t;
};

int power(int x, int n)
{
    if (n == 1)
    {
        return x;
    }
    else
    {
        return power(x, n - 1) * x;
    }
}

void storeCoefficientAndExp(struct polynomial *p)
{
    int i;
    printf("Number of height exponent \n");
    scanf("%d", &p->n);
    p->t = (struct tarm *)malloc(p->n * sizeof(struct tarm));
    printf("Coffiecient and exponent \n");
    for (i = 0; i < p->n; i++)
    {
        scanf("%d%d", &p->t[i].coefficient, &p->t[i].exponent);
    }
}
void resultPoly(struct polynomial p, int x)
{
    int i, result = 0;
    for (i = 0; i < p.n; i++)
    {
        result += power(x, p.t[i].exponent) * p.t[i].coefficient;
    }
    printf("Result is: %d \n", result);
}

int main()
{
    struct polynomial p;
    storeCoefficientAndExp(&p);
    resultPoly(p, 2);

    return 0;
}
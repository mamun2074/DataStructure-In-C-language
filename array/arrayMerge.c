#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct array
{
    int ar[8];
    int length;
    int size;
};
void arrayMerge(struct array arrA, struct array arrB, struct array *arrC)
{
    int i = 0, j = 0, k = 0;
    while (i < arrA.length && j < arrB.length)
    {
        if (arrA.ar[i] < arrB.ar[j])
        {
            arrC->ar[k++] = arrA.ar[i++];
        }
        else
        {
            arrC->ar[k++] = arrB.ar[j++];
        }
    }

    while (i < arrA.length)
    {
        /* code */
        arrC->ar[k++] = arrA.ar[i++];
    }
    while (j < arrB.length)
    {
        /* code */
        arrC->ar[k++] = arrB.ar[j++];
    }

    arrC->length = arrA.length + arrB.length;
    arrC->size=10;
}

void dispaly(struct array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.ar[i]);
    }
    printf(" \n");
}

int main()
{
    struct array arA = {{3, 8, 16, 24}, 4, 8};
    struct array arB = {{4, 10, 12, 22}, 4, 8};
    struct array arC;

    arrayMerge(arA, arB, &arC);

    dispaly(arA);
    dispaly(arB);
    dispaly(arC);

    return 0;
}
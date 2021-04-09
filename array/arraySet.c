#include <stdio.h>

struct array
{
    int arr[10];
    int length;
    int size;
};

void display(struct array ar)
{
    int i;
    for (i = 0; i < ar.length; i++)
    {
        printf("%d ", ar.arr[i]);
    }
    printf(" \n");
}

// union unsorted array o(n2)
void unionUnsortedArray(struct array arA, struct array arB, struct array *arC)
{
    int i, j, k, m, p;
    i = j = k = 0;
    for (i = 0; i < arA.length; i++)
    {
        arC->arr[k++] = arA.arr[i];
    }
    arC->length = arA.length;

    for (j = 0; j < arB.length; j++)
    {
        p = 0;
        for (m = 0; m < arC->length; m++)
        {
            if (arB.arr[j] == arC->arr[m])
            {
                p = 1;
                break;
            }
        }
        if (p == 0)
        {
            arC->arr[k++] = arB.arr[j];
            arC->length++;
        }
    }
}

// union sorted array O(n)
void unionSortedArray(struct array arA, struct array arB, struct array *arC)
{
    int i, j, k;
    i = j = k = 0;
    arC->length = 0;
    while (i < arA.length && j < arB.length)
    {
        if (arA.arr[i] < arB.arr[j])
        {
            arC->arr[k++] = arA.arr[i++];
            arC->length++;
        }
        else if (arA.arr[i] == arB.arr[j])
        {
            arC->arr[k++] = arA.arr[i++];
            j++;
            arC->length++;
        }
        else if (arA.arr[i] > arB.arr[j])
        {
            arC->arr[k++] = arB.arr[j++];
            arC->length++;
        }
    }
    while (i < arA.length)
    {
        /* code */
        arC->arr[k++] = arA.arr[i++];
        arC->length++;
    }
    while (j < arB.length)
    {
        /* code */
        arC->arr[k++] = arB.arr[j++];
        arC->length++;
    }
}

// intersection unsorted arrays O(n2)
void intersectionUnsortedArray(struct array arA, struct array arB, struct array *arC)
{
    int i, j, k, flag;
    k = 0;
    for (i = 0; i < arA.length; i++)
    {
        flag = 0;
        for (j = 0; j < arB.length; j++)
        {
            if (arA.arr[i] == arB.arr[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            arC->arr[k++] = arA.arr[i];
            arC->length++;
        }
    }
}

// intersection sorted arrays O(n)
void intersectionSortedArray(struct array arA, struct array arB, struct array *arC)
{
    int i, j, k;
    i = j = k = 0;
    while (i < arA.length && j < arB.length)
    {
        /* code */
        if (arA.arr[i] == arB.arr[j])
        {
            arC->arr[k++] = arA.arr[i++];
            j++;
            arC->length++;
        }
        else if (arA.arr[i] < arB.arr[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}

int main()
{
    // struct array arrA = {{3, 5, 10, 4, 6}, 5, 8};
    // struct array arrB = {{12, 4, 7, 2, 5}, 5, 8};

    struct array arrA = {{3, 4, 5, 6, 10}, 5, 8};
    struct array arrB = {{2, 4, 5, 7, 12}, 5, 8};

    struct array arrC;
    arrC.size = 10;
    arrC.length = 0;
    display(arrA);
    display(arrB);
    intersectionSortedArray(arrA, arrB, &arrC);
    display(arrC);
    return 0;
}
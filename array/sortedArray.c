#include <stdio.h>
#include <stdbool.h>

// Declar structure of array
struct array
{
    int ar[8];
    int length;
    int size;
};

// Display all array item
void display(struct array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.ar[i]);
    }
    printf(" \n");
}
// Check array is sorted
bool isSorted(struct array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.ar[i] > arr.ar[i + 1])
            return false;
    }
    return true;
}
// Insert an item on sorted array
void insertItemOnSortedArray(struct array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length <= arr->size)
    {
        while (arr->ar[i] > x && i > -1)
        {
            arr->ar[i + 1] = arr->ar[i];
            i--;
        }
        arr->ar[i + 1] = x;
        arr->length++;
    }
}

// Flip item
void Flip(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Arranging array left side is negative and right side is positive
void ArrangingArray(struct array *ar)
{
    int i, j;
    i = 0;
    j = ar->length - 1;

    while (i < j)
    {
        /* code */
        while (ar->ar[i] < 0)
        {
            i++;
        }
        while (ar->ar[j] >= 0)
        {
            j--;
        }
        if (i < j)
            Flip(&ar->ar[i], &ar->ar[j]);
    }
}

// Driver function
int main()
{
    struct array ar = {{2, -3, -5, 22, -10, 12}, 6, 8};

    // insertItemOnSortedArray(&ar, 8);
    ArrangingArray(&ar);

    display(ar);

    return 0;
}
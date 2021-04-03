#include <stdio.h>
#include<stdbool.h>

// Declar structure of array
struct array
{
    int ar[5];
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
    for (i = 0; i < arr.length-1; i++)
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

// Driver function
int main()
{
    struct array ar = {{2, 3, 5}, 3, 5};

    // insertItemOnSortedArray(&ar, 8);

    printf("is sorted %d", isSorted(ar));

    return 0;
}
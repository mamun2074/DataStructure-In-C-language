#include <stdio.h>

struct Array
{
    int arr[10];
    int length;
    int size;
};

void SwapArray(int *formIndex, int *toIndex)
{
    int *temp;
    temp = formIndex;
    formIndex = toIndex;
    toIndex = temp;
}

int LinearSearch(struct Array *arr, int searchItem)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (arr->arr[i] == searchItem)
        {
            SwapArray(&arr->arr[i], &arr->arr[0]);
            return i-1;
        }
    }
    return -1;
}

int main()
{

    struct Array ar = {{2, 3, 4, 5, 6, 7}, 6, 10};

    int x;
    x = LinearSearch(&ar, 7);

    printf("%d \n", x);

    printf("%d", ar.arr[x]);

    return 0;
}
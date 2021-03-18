#include <stdio.h>


struct Array
{
    int arr[20];
    int length;
    int size;
};
void display(struct Array arr)
{
    int i;
    printf("Show all array items \n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.arr[i]);
    }
    printf(" \n");
}

int deleteIndex(struct Array *ar, int index)
{
    int x, i;
    if (index >= 0 && index < ar->length)
    {
        x = ar->arr[index];
        for (i = index; i < ar->length - 1; i++)
        {
            ar->arr[i] = ar->arr[i + 1];
        }
        ar->length--;
        return x;
    }
    return 0;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6}, 6, 20};

    display(arr);

    printf("%d\n", deleteIndex(&arr, 5));
    display(arr);

    return 0;
}
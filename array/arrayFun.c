#include <stdio.h>

// Array structer
struct array
{
    int arr[15];
    int size;
    int length;
};

// Finding value by index
int Get(struct array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.arr[index];
    }
}

// Set value in index
void Set(int arr[], int length, int index, int x)
{
    if (index >= 0 && index < length)
    {
        arr[index] = x;
    }
}

int main()
{
    struct array arr = {{5, 8, 10, 12, 15, 20, 25, 27, 28, 35, 40}, 15, 11};

    Set(arr.arr, arr.length, 1, 200);

    printf("Value is : %d", Get(arr,1));

    return 0;
}
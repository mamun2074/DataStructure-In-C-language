#include <stdio.h>

// Array structer
struct array
{
    int arr[12];
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

// Find Max value
int Max(struct array arr)
{
    int max, i;
    max = arr.arr[0];
    for (i = 1; i < arr.length; i++)
    {
        if (arr.arr[i] > max)
        {
            max = arr.arr[i];
        }
    }
    return max;
}

// Find minimum value on array
int Min(struct array arr)
{
    int min, i;
    min = arr.arr[0];
    for (i = 1; i < arr.length; i++)
    {
        if (min > arr.arr[i])
        {
            min = arr.arr[i];
        }
    }
    return min;
}

int main()
{
    struct array arr = {{5, 8, 10, 12, 15, 20, 25, 27, 28, 35, 40}, 12, 11};

    Set(arr.arr, arr.length, 1, 200);

    printf("Value is : %d", Min(arr));

    return 0;
}
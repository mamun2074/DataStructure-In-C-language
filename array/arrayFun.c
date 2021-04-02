#include <stdio.h>

struct array
{
    int arr[15];
    int size;
    int length;
};

int Get(struct array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.arr[index];
    }
}

int main()
{
    struct array arr = {{5, 8, 10, 12, 15, 20, 25, 27, 28, 35, 40}, 15, 11};

    printf("Value is : %d", Get(arr, 3));

    return 0;
}
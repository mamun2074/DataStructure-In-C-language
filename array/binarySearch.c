#include <stdio.h>

struct Array
{
    int Arr[10];
    int length;
    int size;
};

int BinarySearch(struct Array ar, int searchingItem)
{
    int left, mid, right;

    left = 0;
    right = ar.length - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (searchingItem == ar.Arr[mid])
            return mid;
        else if (searchingItem > ar.Arr[mid])
            left = mid + 1;
        else if (searchingItem < ar.Arr[mid])
            right = mid - 1;
    }
    return -1;
}

int RecBinarySearch(int arr[], int low, int high, int key)
{
    int mid; 
    if (low <= high)
    {
        mid = ((low + high) / 2);
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            RecBinarySearch(arr, low, mid - 1, key);
        else
            RecBinarySearch(arr, mid+1, high, key);
    }
    else
        return -1;
}

int main()
{

    struct Array ar = {{1, 3, 5, 6, 7}, 5, 10};

    printf("%d", RecBinarySearch(ar.Arr, 0, 4, 6));

    return 0;
}
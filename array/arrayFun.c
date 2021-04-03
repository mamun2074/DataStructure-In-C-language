#include <stdlib.h>
#include <stdio.h>

// Array structer
struct array
{
    int arr[12];
    int size;
    int length;
};

void display(struct array arr)
{
    int i;
    printf("Show all array items \n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.arr[i]);
    }
    printf(" \n");
}

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

// Sum all item on array
int Sum(struct array arr)
{
    int sum = 0, i;
    for (i = 0; i < arr.length; i++)
    {
        sum += arr.arr[i];
    }
    return sum;
}

// Sum array recursion
int SumR(struct array arr, int n)
{
    if (n < 0)
    {
        return 0;
    }
    else
    {
        return SumR(arr, n - 1) + arr.arr[n];
    }
}

// Avarage on array
int Avg(struct array arr)
{
    return (Sum(arr) / arr.length);
}

void Reverse(struct array *arr)
{
    int *helpingArray, i, j;
    helpingArray = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        helpingArray[j] = arr->arr[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->arr[i] = helpingArray[i];
    }
}

void Flip(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Reverse1(struct array *arr)
{
    int i, j, temp, *a, *b;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        Flip(&arr->arr[i], &arr->arr[j]);
    }
}

int main()
{
    struct array arr = {{5, 8, 10, 12, 15, 20, 25, 27, 28, 35, 40}, 12, 11};

    Reverse1(&arr);

    display(arr);

    return 0;
}
#include <stdio.h>

int main()
{

    int arr[10] = {2, 3, 4, 5, 6}, length = 5, index = 4, value = 10;

    for (int i = length; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index]=value;
    length++;

    printf("Show all item \n");
    for(int x=0; x<length; x++)
        printf("%d ", arr[x]);

    printf(" \n");

    return 0;
}
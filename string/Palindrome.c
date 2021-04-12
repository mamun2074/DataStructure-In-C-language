#include <stdio.h>
#include <stdbool.h>

bool IsPalindrome(char A[])
{
    int i, j;
    for (j = 0; A[j] != '\0'; j++)
    {
        if ((A[j] >= 'a' && A[j] <= 'z') || (A[j] >= 'A' && A[j] <= 'Z'))
        {
            if (A[j] >= 'A' && A[j] <= 'Z')
            {
                A[j] = A[j] + 32;
            }
        }
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        if (A[i] != A[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    char A[] = "Agga";

    printf(" Is Palindrom: %d\n", IsPalindrome(A));

    return 0;
}
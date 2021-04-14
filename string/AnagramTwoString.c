#include <stdio.h>

int isAnagram(char a[], char b[])
{
    int i, j;
    int letter[26] = {0};

    for (i = 0; a[i] != '\0'; i++)
    {
    }
    for (j = 0; b[j] != '\0'; j++)
    {
    }

    if (i == j)
    {

        for (i = 0; a[i] != '\0'; i++)
        {
            letter[a[i] - 97] += 1;
        }

        for (i = 0; b[i] != '\0'; i++)
        {
            letter[b[i] - 97] -= 1;
            if (letter[b[i] - 97] < 0)
            {
                return 0;
            }
        }
        if (b[i] == '\0')
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int main()
{

    char a[] = "decimal";
    char b[] = "medical";
    int flag;
    flag = isAnagram(a, b);
    if (flag)
    {
        printf("Anagram");
    }else{
        printf("Not Anagram");
    }
    return 0;
}
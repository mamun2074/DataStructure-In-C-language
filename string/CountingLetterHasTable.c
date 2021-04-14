#include <stdio.h>

int *countDuplicateLetter(char name[])
{
    int i;
    static int letter[26];
    for (i = 0; name[i] != '\0'; i++)
    {
        letter[name[i] - 97] += 1;
    }
    return letter;
}

int main()
{
    int i, j;
    int * letter;
    char name[] = "bithi";

    letter = countDuplicateLetter(name);

    for (j = 0; j < 26; j++)
    {
        if (letter[j] > 1)
        {
            printf("Duplicate letter is: %c, and number of duplicate: %d", j + 97, letter[j]);
        }
    }

    return 0;
}
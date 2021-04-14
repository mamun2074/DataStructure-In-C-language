#include <stdio.h>
int letter[26];

int main()
{
    int i, j;
    char name[] = "bithi";
    for (i = 0; name[i] != '\0'; i++)
    {
        letter[name[i] - 97] += 1;
    }
    for (j = 0; j < 26; j++)
    {
        if (letter[j] > 1)
        {
            printf("Duplicate Car is: %c, and number of duplicate: %d", j+97 ,letter[j]);
        }
    }

    return 0;
}
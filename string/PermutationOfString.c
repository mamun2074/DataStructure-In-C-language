#include <stdio.h>

void permutationOfString(char s[], int k)
{
    static int flag[3] = {0};
    static char result[3];
    int i;
    if (s[k] == '\0')
    {
        result[k] = '\0';
        printf("%s", result);
        printf("\n");
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (flag[i] == 0)
            {
                result[k] = s[i];
                flag[i] = 1;
                permutationOfString(s, k + 1);
                flag[i] = 0;
            }
        }
    }
}

int main()
{
    char s[] = "abc";

    permutationOfString(s, 0);

    return 0;
}
#include <stdio.h>

int *countingVowlesAndConsonents(char sentense[])
{
    static int arr[3];
    int i, vowel, consonent;
    vowel = 0;
    consonent = 0;

    for (i = 0; sentense[i] != '\0'; i++)
    {
        if (sentense[i] == 'a' || sentense[i] == 'e' || sentense[i] == 'i' || sentense[i] == 'o' || sentense[i] == 'u' || sentense[i] == 'A' || sentense[i] == 'E' || sentense[i] == 'I' || sentense[i] == 'O' || sentense[i] == 'U')
        {
            vowel++;
        }
        else if ((sentense[i] >= 'A' && sentense[i] <= 'Z') || (sentense[i] >= 'a' && sentense[i] <= 'z'))
        {
            consonent++;
        }
    }
    arr[0] = vowel;
    arr[1] = consonent;
    return arr;
}
int numberOfWords(char sentense[])
{
    int space, i;
    space = 0;
    for (i = 0; sentense[i] != '\0'; i++)
    {
        if (sentense[i] == ' ' && sentense[i-1] !=' ')
            space++;
    }
    if (space == 0)
        return 0;
    else
        return space + 1;
}
int main()
{
    int *numberOfVC;
    char sentense[] = "Hello   Love  your ";
    numberOfVC = countingVowlesAndConsonents(sentense);

    printf("Vowel are: %d and Consonents are: %d \n", numberOfVC[0], numberOfVC[1]);

    printf("Number of words is: %d ", numberOfWords(sentense));

    return 0;
}
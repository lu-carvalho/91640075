#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string text);

int main(void)
{
    //get a string from the user
    string text;
    text = get_string("Text: \n");

    printf("%s\n", text);

    for (int i = 0; i < strlen(text); i++)
    {
        count_letters(text);
    }
}

int count_letters(string text)
{
    int letters;
    int i = 0;

    if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
    {
        letters++;
    }
    return letters;
}
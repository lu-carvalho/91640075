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

    count_letters(text);
}

int count_letters(string text)
{
    int i = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            i++;
        }
    }
    printf("%i letters \n", i);
}
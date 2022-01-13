#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_words(string text);

int main(void)
{
    //get a string from the user
    string text;
    text = get_string("Text: \n");

    printf("%s\n", text);
}

int count_letters(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        count_words(text);
    }
}

int count_words(string text)
{
    int letters;
    if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
    letters++;
    printf("%i letters \n", letters);
}
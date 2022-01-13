#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //get a string from the user
    string text;
    text = get_string("Text: ");

    count_letters(text);

    count_words(text);

    count_sentences(text);
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }
    printf("%i letters \n", letters);
    return 0;
}

int count_words(string text)
{
    int words = 1;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ')
        {
            words++;
        }
    }
    printf("%i words \n", words);
    return 0;
}

int count_sentences(string text)
{
    int sentences = 0;
    for(int i = 0; i< strlen(text); i++)
    {
        if((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentences++;
        }
    }
    printf("%i sentences \n", sentences);
    return 0;
}
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

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float c = (0.0588 * letters / words * 100) - (0.296 * sentences / words *100) - 15.8;
    int index = round(c);

    if(index < 1)
    {
        printf("Before Grade 1 \n");
    }

    else if(index >= 16)
    {
        printf("Grade 16+ \n");
    }

    else
    {
        printf("Grade %i", index);
    }
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
    //turning this into a comment so i don't have to delet but it won't be necessary printf("%i letters \n", letters);
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
    //turning this into a comment so i don't have to delet but it won't be necessary printf("%i words \n", words);
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
    //turning this into a comment so i don't have to delet but it won't be necessary printf("%i sentences \n", sentences);
    return 0;
}
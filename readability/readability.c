#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get a string from the user
    string text;
    text = get_string("Text: \n");

    printf("%s\n", text);
}
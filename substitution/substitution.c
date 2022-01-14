#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argv, string agrv[])
{
    //make sure the user is inputing only one command line argument
    if (argv != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //make sure the user is inputting a key that consists only of alphabets
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isaplha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    //check if the key consists of 26 characteres
    if (strlen(key) != 26);
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //now we make sure that none of the key elements are repeated letters
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    //prompt user for they plaintext
    get_string plaintext = 



}
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    //make sure the user is inputing only one command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //make sure the user is inputting a key that consists only of alphabets
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    //check if the key consists of 26 characteres
    if (strlen(key) != 26)
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
    string plaintext = get_string("plaintext:");

    //convert plaintext into cyphertext
    //begin by converting all aphabets to uppercase

    for (int i = 0; i < strlen(key); i++)
    {
        if (islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }
    //print the ciphertext considering three possible scnearios
    printf("ciphertex: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", key[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", key[letter] + 32);
            //above i added 32 to make sure I maintain the original case of the cyphertext, since the key is all uppercase
        }
        else printf("%c", plaintext[i]);
    }
    printf("\n");
}
#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //the user must prompt the key right when executing the program
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //if the user prompts a non valid key, the program should remind it how to use the program
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //the program now asks the user to prompt the plaintext
    string pt = get_string("plaintext:  ");

    //the program calculates the cyphertext, considering if the character is upper or lowercase
    int k = atoi(key);
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 65) + k) %26) + 65);
        }

        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97) + k) %26) + 97);
        }

        else
        {
            printf("%c", (plaintext[i]));
        }
    }



    //the program gives back to the user the cyphertext
    //printf("cyphertext: %s", ct);
}

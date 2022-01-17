#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <cstype.h>
#include <math.h>

int main(int argc, string argv[])
{
    //the user must prompt the key right when executing the program
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //if the user prompts a non valid key, the program should remind it how to use the program
    string k = argv[1];
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isdigit(k[i]))
        {
            printf("key\n")
            return 1;
        }
    }

    //the program now asks the user to prompt the plaintext
    string pt = get_string("plaintext:  ");

    //the program calculates the cyphertext



    //the program gives back to the user the cyphertext
    printf("cyphertext: %s", ct);
}

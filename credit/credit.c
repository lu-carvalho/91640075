#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get the card number from the user
    long n;
    n = get_long("Number: \n");

    //count length of the number
    int i = 0;
    int cc = n;
    while (cc > 0)
    {
        cc = cc/10;
        i++;
    }

    //having the length, we'll check if it's valid considering the 3 possible lenghts

    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //if the lengh is adequate, the sum must be calculated
    
}
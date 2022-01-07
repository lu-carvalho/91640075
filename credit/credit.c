#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get the card number from the user
    long n;
    n = get_long("Number: \n");

    //count length of the number to see if its addequate
    int i = 0;
    int cc = n;
    while (cc > 0)
    {
        cc = cc/10;
        i++;
    }
}
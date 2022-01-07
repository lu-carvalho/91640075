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

    int sum1 = 0;
    int sum2 = 0;
    long x = n;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;

    do
    {
        //remove the last digit and add to sum1
        mod1 = x % 10;
        x = x/10;
        sum1 = sum1 + mod1;

        //remove the second last digit and add digits to sum2
        mod2 = x % 10;
        x = x/10;

        //double the last digit and add its digits to sum2
    }



    long x = n;
}
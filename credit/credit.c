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
        cc = cc / 10;
        i++;
    }

    //having the length, we'll check if it's valid considering the 3 possible lenghts

    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID1\n");
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
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2/10;
        sum2 = sum2 + d1 + d2;
    }
    while(x > 0);

    total = sum1 + sum2;

    //now we check if it passes the algorithm
    if(total % 10 != 0)
    {
        printf("INVALID2\n");
        return 0;
    }

    //great, all set, now we will extract the first two digits
    long start = n;
    do
    {
        start = start/10;
    }
    while(start > 100);

    //check if it is a mastercard card
    if((start/10 == 5) && (start%10 == 1 || start%10 == 2 || start%10 == 3 || start%10 == 4 || start%10 == 5))
    {
        printf("MASTERCARD\n");
    }

    //or a amex card
    if((start/10 == 3) && (start%10 == 7 || start%10 ==4))
    {
        printf("AMEX\n");
    }

    //last but not least, or a visa card
    else if(start/10 == 4)
    {
        printf("VISA\n");
    }

    //if none of those are true, than
    else
    {
        printf("INVALID3\n");
        return 0;
    }


}
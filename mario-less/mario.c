#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int x;
    do
    {
        x = get_int("Write a number from 1 to 8: \n");
    }
    while (x < 1 || x > 8);

    for (int i = 0; i < x; i++)
    {
        for (int d = x - 1; d > i; d--)
        {
            printf(" ");
        }
        for (int h = -1; h < i; h++)
        {
            printf("#");
        }
        printf("\n");
    }
}
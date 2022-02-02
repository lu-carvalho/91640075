#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *image = fopen(argv[1], "r");

    int i = 0;
    int files[i];

    fread(files, sizeof(BYTE), 512, image);

    if (files[0] == 0xff && files[1] == 0xd8 && (files[3] & 0xf0) == 0xe0)
    {
        FILE *image1 = fopen(files[i], )
    }

}
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //require correct usage from user
    if (argc != 2)
    {
        printf("usage: ./recover IMAGE\n");
        return 1;
    }

    //open the memory card file
    FILE *mc = fopen(argv[1], "r");
    if (!mc)
    {
        printf("forensic image cannot be opened for reading\n");
        return 1;
    }

    int i = 0;
    int files[i];
    

    fread(files, sizeof(BYTE), 512, image);

    if (files[0] == 0xff && files[1] == 0xd8 && (files[3] & 0xf0) == 0xe0)
    {
        FILE *image1 = fopen(files[i], )
    }

}
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage ./recover IMAGE\n");
        return 1;
    }


 FILE *files = fopen(argv[1], "r");


 int jpegs[JPEG_SIZE];

 fread(&arr, JPEG_SIZE, 1, );




}
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
    char *input_file = argv[1];
    FILE *input_pointer = fopen(input_file, "r");

    if (input_pointer == NULL)
    {
        printf("forensic image cannot be opened for reading\n");
        return 1;
    }

    BYTE buffer[512];
    int jpg_count = 0;
    FILE *jpg_pointer = NULL;
    char jpg_name[8];

    //read until the end of the file: until argv changes to the third element (2)
    while(fread(&buffer, 512, 1, input_pointer) == 1);
    {
        //try to find a JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer [2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if it is not the first in the memory card:
            if(!(jpg_count == 0))
            {
                fclose(jpg_pointer);
            }

            sprintf(filename, "%03i.jpg", jpg_count);
            jpg_pointer = fopen(filename, "w");
            jpg_count++;
        }

        if (!(jpg_count == 0))
        {
            fwrite(&buffer, 512, 1, jpg_pointer);
        }

        fclose(input_pointer);
        fclose(jpg_pointer);

        return 0;
    }
}
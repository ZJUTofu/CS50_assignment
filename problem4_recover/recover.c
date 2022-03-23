#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK 512

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(!file)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    uint8_t buffer[BLOCK];
    int n = 0;

    char *filename = malloc(sizeof(int) * 3);
    if(!filename)
    {
        return 1;
    }

    sprintf(filename, "%03i.jpg", n);
    FILE *image = fopen(filename, "w");
    if(!image)
    {
        fclose(file);
        printf("Could not recover %s.\n", filename);
        return 1;
    }

    while(fread(buffer, 1, BLOCK, file))
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            fwrite(buffer, 1, BLOCK, image);
            while(fread(buffer, 1, BLOCK, file))
            {
               if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
                {
                    fclose(image);
                    n++;
                    filename = malloc(BLOCK);
                    sprintf(filename, "%03i.jpg", n);
                    image = fopen(filename, "w");
                    fwrite(buffer, 1, BLOCK, image);
                }
                else
                {
                    fwrite(buffer, 1, BLOCK, image);
                }
            }
        }
    }

}
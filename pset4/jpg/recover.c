/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int is_start_of_jpg(BYTE* four_bytes) {
    if (four_bytes[0] != 0xff) { return 0; }
    if (four_bytes[1] != 0xd8) { return 0; }
    if (four_bytes[2] != 0xff) { return 0; }

    switch (four_bytes[3]) {
        case 0xe0:
        case 0xe1:
        case 0xe2:
        case 0xe3:
        case 0xe4:
        case 0xe5:
        case 0xe6:
        case 0xe7:
        case 0xe8:
        case 0xe9:
        case 0xea:
        case 0xeb:
        case 0xec:
        case 0xed:
        case 0xee:
        case 0xef:
        return 1;
        default:
        return 0;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 1)
    {
        printf("Usage: ./recover\n");
        return 1;
    }

    char* infile = "card.raw";
    FILE* inptr = fopen(infile, "rb");
    FILE* outptr = NULL;
    size_t block_size = (size_t) 512;

    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    BYTE* new_block;
    new_block = malloc(block_size);

    char outfile[8];
    int file_number=0;

    int file_not_finished = 0;
    file_not_finished = fread(new_block, block_size, 1, inptr);


    do {

        if(is_start_of_jpg(new_block)) {

            sprintf(outfile, "%03d.jpg", file_number);

            outptr = fopen(outfile, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", outfile);
                return 3;
            }

            do {
                fwrite(new_block, block_size, 1, outptr);
                file_not_finished = (int) fread(new_block, block_size, 1, inptr);
            } while(!is_start_of_jpg(new_block) && file_not_finished);
            file_number++;
            fclose(outptr);
        } else {
            file_not_finished = (int) fread(new_block, block_size, 1, inptr);
        }

    } while(file_not_finished);

    free(new_block);
    fclose(inptr);
    return 0;
}

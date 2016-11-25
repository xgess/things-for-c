/*
 * resizing. mostly copied from copy.c
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"



BITMAPFILEHEADER resize_file_header(BITMAPFILEHEADER input, int multiplier) {
    BITMAPFILEHEADER output = input;
    // bfOffBits is always 54
    output.bfSize= (DWORD) ((input.bfSize - input.bfOffBits) * multiplier * multiplier + input.bfOffBits); //246 => 822
    return output;
}

BITMAPINFOHEADER resize_info_header(BITMAPINFOHEADER input, int multiplier) {
    BITMAPINFOHEADER output = input;
    // biSize is always 40
    // biBitCount is always 24
    output.biWidth = (LONG) (input.biWidth * multiplier);
    output.biHeight = (LONG) (input.biHeight * multiplier);
    output.biSizeImage = (DWORD) (input.biSizeImage * multiplier * multiplier); //192 => 768;
    return output;
}


int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // BITMAPFILEHEADER
    BITMAPFILEHEADER bf_in, bf_out;
    fread(&bf_in, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_out = resize_file_header(bf_in, n);

    // BITMAPINFOHEADER
    BITMAPINFOHEADER bi_in, bi_out;
    fread(&bi_in, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_out = resize_info_header(bi_in, n);

    // ensure infile is (likely) track_padding 24-bit uncompressed BMP 4.0
    if (bf_in.bfType != 0x4d42 || bf_in.bfOffBits != 54 || bi_in.biSize != 40 ||
        bi_in.biBitCount != 24 || bi_in.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER & BITMAPINFOHEADER
    fwrite(&bf_out, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi_out, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int input_padding =  (4 - (bi_in.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int output_padding =  (4 - (bi_out.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile rows
    for (int i = 0, biHeight = abs(bi_in.biHeight); i < biHeight; i++) {
        // read the entire row into an array of pixels
        RGBTRIPLE pixels[bi_in.biWidth];
        for (int j = 0; j < bi_in.biWidth; j++) {
            fread(&pixels[j], sizeof(RGBTRIPLE), 1, inptr);
        }
        // step over any padding there might be on the input row
        fseek(inptr, input_padding, SEEK_CUR);

        // write each row N times
        for (int rows_per_multiple = 0; rows_per_multiple < n; rows_per_multiple++) {
            // for each pixel of the input
            for (int k = 0; k < bi_in.biWidth; k++) {
                //write each pixel N times
                for (int multiple_pixels = 0; multiple_pixels < n; multiple_pixels++) {
                    fwrite(&pixels[k], sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            // add padding to the output row if necessary
            for (int track_padding = 0; track_padding < output_padding; track_padding++) {
                fputc(0x00, outptr);
            }
        }
    }

    fclose(inptr);
    fclose(outptr);
    return 0;
}

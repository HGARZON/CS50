#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }

    int scaleFactor = atoi(argv[1]);
    int bytes = 0;

    if (scaleFactor < 1 || scaleFactor > 100)
    {
        printf("Second argument must be between 1 and 100 inclusive\n");
        return 5;
    }

    // remember filenames
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

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf_res;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_res = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_res;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_res = bi;

    printf("biSizeImage Original Image %d\n", bi.biSizeImage);
    printf("bfSize Original Image %d\n", bf.bfSize);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // change width/height
    bi_res.biWidth = bi.biWidth * scaleFactor;
    bi_res.biHeight = bi.biHeight * scaleFactor;

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_res = (4 - (bi_res.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    printf("padding_res %d\n", padding_res);

    // change file sizes in headers
    bi_res.biSizeImage = (bi_res.biWidth * sizeof(RGBTRIPLE) + padding_res) * abs(bi_res.biHeight);
    printf("biSizeImage %d\n", bi_res.biSizeImage);
    bf_res.bfSize = bf.bfSize - bi.biSizeImage + bi_res.biSizeImage;
    printf("bfSize %d\n", bf_res.bfSize);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_res, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_res, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++) {
        printf("I %d\n", i);
        int position = ftell(inptr);

        for (int f = 0; f < scaleFactor; f++) {
            printf("F %d\n", f);
            fseek(inptr, position, SEEK_SET);
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++) {
                printf("J %d\n", j);
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int k = 0; k < scaleFactor; k++) {
                    printf("K %d\n", k);
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    bytes += 3;
                    printf("bytes %d\n:", bytes);
                }
            }

            // Add padding for resized image
            for (int k = 0; k < padding_res; k++) {
                fputc(0x00, outptr);
                bytes += 1;
                printf("padding %d\n", k);
                printf("bytes padding %d\n:", bytes);
                printf("Add padding for resized image\n");
            }

        }

        // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
            printf("Skip over padding\n");
    }

    printf("bytes %d\n:", bytes);

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
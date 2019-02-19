# Questions

## What's `stdint.h`?

This header defines a set of integral type aliases with specific width requirements, along with macros specifying their limits and macro functions to create values of these types.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

They let us define an integer type with a width of exactly 8, 16, 32, or 64 bits.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 8 bits = 1 byte
DWORD= 32 bits = 4 bytes
LONG = signed 32 bits = 4 bytes
WORD = 16 bits = 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

Hex:    0x424d
ASCII:  BM (bitmap!)
This value is stored in "bfType".

## What's the difference between `bfSize` and `biSize`?

bfSize is the total size of file (in bytes), and include pixels, padding and header.
biSize on the other hand, is the number of bytes in the info header.

## What does it mean if `biHeight` is negative?

biHeight is the total height of the image in pixels.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the input file cannot be opened for reading or the output file cannot be opened for writing, those lines return a "Null safe" value.

## Why is the third argument to `fread` always `1` in our code?

Becouse 1 is the number of elements to read. In this case, is one file.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

0.

## What does `fseek` do?

The C library function int fseek(FILE *stream, long int offset, int whence) sets the file position of the stream to the given offset.

## What is `SEEK_CUR`?

SEEK_CUR is the current position of the file pointer

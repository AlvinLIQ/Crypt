#include <string.h>
#include <stdlib.h>

#define universal 1

#define schar signed char
#define uchar unsigned char

uint tellmewhere (const uchar* str, const uchar chr, uint sLen)
{
    while (sLen && chr != str[--sLen]);
    return sLen;
}

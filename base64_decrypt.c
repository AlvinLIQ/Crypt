#include <stdio.h>
#include <string.h>

#define sdn argv[1]
#define uchar unsigned char
#define schar signed char

const uchar cip[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

uchar tellmewhere (uchar s)
{
    uchar i = 64;

    while (--i >= 0)
        if (s == cip[i])
            break;
    return i;
}

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        printf ("[usage]\n ./xx [str]\n");
        return -1;
    }
    
    int sLen = strlen(sdn);
    
    schar offset = 0;
    uchar result[255] = "", sIndex;
    for (int i = 0, j = 0; i < sLen && sdn[i] != '='; i++)
    {            
        sIndex = tellmewhere (sdn[i]);
        result[j] += offset < 2 ? sIndex << 2 - offset : sIndex >> offset - 2;
        offset += 6;
        if (offset > 8)
        {
            offset -= 8;
            result[++j] = 0;
            result[j] = sIndex << 8 - offset;
        }
    }
    printf ("%s\n", result);
    return 0;
}

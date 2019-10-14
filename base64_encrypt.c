#include <stdio.h>
#include <string.h>

#define sdn argv[1]
#define uchar unsigned char

const char cip[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        printf ("[usage]\n ./xx [str]\n");
        return -1;
    }

    uchar result[255], offset = 0, b = 2, sLen = strlen (sdn);
    for (uchar i = 0, j = 0; i < sLen; i++, j++, b += 2)
    {
        result[j] = offset + (sdn[i] >> b);
        printf ("%c", cip[result[j]]);
        offset = sdn[i] << 8 - b;
        offset >>= 2;

        if (i + 1 == sLen || b == 6)
        {
            result[++j] = offset;
            printf ("%c", cip[result[j]]);
            b = 0;
            offset = 0;
        }
    }

    sLen = 3 - sLen % 3;
    if (sLen <= 2)
        while (sLen--)
            printf ("=");
    printf ("\n");
    return 0;
}

#include "aes.h"

#include <stdio.h>

int main(int argc, uchar** argv)
{
    if (argc < 2)
        return -1;
        
	printf("%s\n", aes128_encrypt(argv[1], "000"));
	return 0;
}

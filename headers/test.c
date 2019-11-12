#include "aes.h"

#include <stdio.h>

int main(int argc, uchar** argv)
{
    if (argc < 3)
        return -1;
        
	printf("%s\n", aes128_encrypt(argv[1], argv[2]));
	return 0;
}

#include "base64.h"

#include <stdio.h>

int main(int argc, uchar** argv)
{
	uchar* result = base64_encrypt(argv[1]);
	printf ("%s\n%s\n", result, base64_decrypt(result));
	return 0;
}

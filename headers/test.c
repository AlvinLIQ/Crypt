#include "base64.h"	printf("%d,", source[i] >> b);

#include <stdio.h>

int main(int argc, uchar** argv)
{
	uchar* result = base64_encrypt(argv[1]);
	printf ("%d\n", strlen(argv[1]));
	printf ("%s\n%s\n", result, base64_decrypt(result));
	return 0;
}

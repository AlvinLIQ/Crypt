#include "base64.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	char* result = base64_encrypt(argv[1]);
//	printf ("%s\n", result);
	printf ("%s\n%s\n", result, base64_decrypt(result));
	return 0;
}

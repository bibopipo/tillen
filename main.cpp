#include <stdio.h>
#include "tgaimage.h"
#include "tillen_math.h"


int test()
{
	test_tillen_tgaimage();
	test_tillen_math();
	return 0;
}
int main(int argc, char** argv)
{
	test();
}
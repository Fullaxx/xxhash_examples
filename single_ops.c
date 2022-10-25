#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xxhash.h"

void ss_xxh32(const char *string)
{
	size_t length;
	XXH32_hash_t hval;

	length = (string) ? strlen(string) : 0;
	hval = XXH32(string, length, 0);
	printf("SShot XXH32     0x                         %08x\n", hval);
}

void ss_xxh64(const char *string)
{
	size_t length;
	XXH64_hash_t hval;

	length = (string) ? strlen(string) : 0;
	hval = XXH64(string, length, 0);
	printf("SShot XXH64     0x                 %016lx\n", hval);
}

void ss_xxh3_64bits(const char *string)
{
	size_t length;
	XXH64_hash_t hval;

	length = (string) ? strlen(string) : 0;
	hval = XXH3_64bits(string, length);
	printf("SShot XXH3(64)  0x                 %016lx\n", hval);
}

void ss_xxh3_128bits(const char *string)
{
	size_t length;
	XXH128_hash_t hval;

	length = (string) ? strlen(string) : 0;
	hval = XXH3_128bits(string, length);
	printf("SShot XXH3(128) 0x %016lx%016lx\n", hval.high64, hval.low64);
}

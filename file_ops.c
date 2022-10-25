#include <stdio.h>
#include <string.h>

#include "xxhash.h"

static int xxh32_FILE(FILE *f, XXH32_hash_t *hptr)
{
	size_t n;
	char buf[4096];
	XXH32_state_t *state = XXH32_createState();
	if(!state) { return -1; }

	XXH32_reset(state, 0);
	while ((n = fread(buf, 1, sizeof(buf), f)) != 0) {
		XXH32_update(state, buf, n);
	}

	*hptr = XXH32_digest(state);
	XXH32_freeState(state);
	return 0;
}

void file_xxh32(const char *path)
{
	int z;
	FILE *f;
	XXH32_hash_t hval;

	f = fopen(path, "r");
	if(!f) { fprintf(stderr, "fopen(%s, r) FAIL!\n", path); return; }

	z = xxh32_FILE(f, &hval);
	fclose(f);
	if(z) { fprintf(stderr, "xxh32_FILE(%s) FAIL!\n", path); return; }
	printf("File  XXH32     0x                         %08x\n", hval);
}

static int xxh64_FILE(FILE *f, XXH64_hash_t *hptr)
{
	size_t n;
	char buf[4096];
	XXH64_state_t *state = XXH64_createState();
	if(!state) { return -1; }

	XXH64_reset(state, 0);
	while ((n = fread(buf, 1, sizeof(buf), f)) != 0) {
		XXH64_update(state, buf, n);
	}

	*hptr = XXH64_digest(state);
	XXH64_freeState(state);
	return 0;
}

void file_xxh64(const char *path)
{
	int z;
	FILE *f;
	XXH64_hash_t hval;

	f = fopen(path, "r");
	if(!f) { fprintf(stderr, "fopen(%s, r) FAIL!\n", path); return; }

	z = xxh64_FILE(f, &hval);
	fclose(f);
	if(z) { fprintf(stderr, "xxh64_FILE(%s) FAIL!\n", path); return; }
	printf("File  XXH64     0x                 %016lx\n", hval);
}

static int xxh3_64_FILE(FILE *f, XXH64_hash_t *hptr)
{
	size_t n;
	char buf[4096];
	XXH3_state_t *state = XXH3_createState();
	if(!state) { return -1; }

	XXH3_64bits_reset(state);
	while ((n = fread(buf, 1, sizeof(buf), f)) != 0) {
		XXH3_64bits_update(state, buf, n);
	}

	*hptr = XXH3_64bits_digest(state);
	XXH3_freeState(state);
	return 0;
}

void file_xxh3_64(const char *path)
{
	int z;
	FILE *f;
	XXH64_hash_t hval;

	f = fopen(path, "r");
	if(!f) { fprintf(stderr, "fopen(%s, r) FAIL!\n", path); return; }

	z = xxh3_64_FILE(f, &hval);
	fclose(f);
	if(z) { fprintf(stderr, "xxh3_64_FILE(%s) FAIL!\n", path); return; }
	printf("File  XXH3(64)  0x                 %016lx\n", hval);
}

static int xxh3_128_FILE(FILE *f, XXH128_hash_t *hptr)
{
	size_t n;
	char buf[4096];
	XXH128_hash_t digest;
	XXH3_state_t *state = XXH3_createState();
	if(!state) { return -1; }

	XXH3_128bits_reset(state);
	while ((n = fread(buf, 1, sizeof(buf), f)) != 0) {
		XXH3_128bits_update(state, buf, n);
	}

	digest = XXH3_128bits_digest(state);
	memcpy(hptr, &digest, sizeof(XXH128_hash_t));
	XXH3_freeState(state);
	return 0;
}

void file_xxh3_128(const char *path)
{
	int z;
	FILE *f;
	XXH128_hash_t hval;

	f = fopen(path, "r");
	if(!f) { fprintf(stderr, "fopen(%s, r) FAIL!\n", path); return; }

	z = xxh3_128_FILE(f, &hval);
	fclose(f);
	if(z) { fprintf(stderr, "xxh3_128_FILE(%s) FAIL!\n", path); return; }
	printf("File  XXH3(128) 0x %016lx%016lx\n", hval.high64, hval.low64);
}

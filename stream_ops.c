#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xxhash.h"

void stream_xxh32(const char *data)
{
	XXH32_state_t *state;
	XXH32_hash_t hval;

	state = XXH32_createState();
	if (state == NULL) { fprintf(stderr, "NULL!\n"); exit(1); }
	XXH32_reset(state, 0);
	XXH32_update(state, data, strlen(data));
	hval = XXH32_digest(state);
	printf("State XXH32     0x                         %08x\n", hval);
	XXH32_freeState(state);
}

void stream_xxh64(const char *data)
{
	XXH64_state_t *state;
	XXH64_hash_t hval;

	state = XXH64_createState();
	if (state == NULL) { fprintf(stderr, "NULL!\n"); exit(1); }
	XXH64_reset(state, 0);
	XXH64_update(state, data, strlen(data));
	hval = XXH64_digest(state);
	printf("State XXH64     0x                 %016lx\n", hval);
	XXH64_freeState(state);
}

void stream_xxh3_64(const char *data)
{
	XXH3_state_t *state;
	XXH64_hash_t hval;

	state = XXH3_createState();
	if (state == NULL) { fprintf(stderr, "NULL!\n"); exit(1); }
	XXH3_64bits_reset(state);
	XXH3_64bits_update(state, data, strlen(data));
	hval = XXH3_64bits_digest(state);
	printf("State XXH3(64)  0x                 %016lx\n", hval);
	XXH3_freeState(state);
}

void stream_xxh3_128(const char *data)
{
	XXH3_state_t *state;
	XXH128_hash_t hval;

	state = XXH3_createState();
	if (state == NULL) { fprintf(stderr, "NULL!\n"); exit(1); }
	XXH3_128bits_reset(state);
	XXH3_128bits_update(state, data, strlen(data));
	hval = XXH3_128bits_digest(state);
	printf("State XXH3(128) 0x %016lx%016lx\n", hval.high64, hval.low64);
	XXH3_freeState(state);
}

#include <stdio.h>

/* Single Shot Prototypess */
void ss_xxh32(const char *);
void ss_xxh64(const char *);
void ss_xxh3_64bits(const char *);
void ss_xxh3_128bits(const char *);

/* Streaming Prototypess */
void stream_xxh32(const char *);
void stream_xxh64(const char *);
void stream_xxh3_64(const char *);
void stream_xxh3_128(const char *);

/* File Prototypess */
void file_xxh32(const char *);
void file_xxh64(const char *);
void file_xxh3_64(const char *);
void file_xxh3_128(const char *);

int main(int argc, char *argv[])
{
	/* Single Shot Functions */
	ss_xxh32("mystring");
	ss_xxh64("mystring");
	ss_xxh3_64bits("mystring");
	ss_xxh3_128bits("mystring");

	printf("\n");

	/* Steaming Functions */
	stream_xxh32("mystring");
	stream_xxh64("mystring");
	stream_xxh3_64("mystring");
	stream_xxh3_128("mystring");

	printf("\n");

	/* File Functions */
	file_xxh32("tests/mystring.txt");
	file_xxh64("tests/mystring.txt");
	file_xxh3_64("tests/mystring.txt");
	file_xxh3_128("tests/mystring.txt");

	return 0;
}

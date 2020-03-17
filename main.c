#include <stdio.h>
#include <assert.h>
#include <unistd.h>

#include "Gost.h"
#include "util.h"


int main (int argc, char** argv)
{
	assert(argc > 1);
	assert( (access(argv[1], F_OK)) != -1 && "файла не существует") ;

	FILE * f;
	char* buffer;
	long filelen;

    f = fopen(argv[1], "w");
    fprintf(f, "abc");
    fclose(f);
    f = fopen(argv[1], "rb");
    fseek(f, 0, SEEK_END);
	filelen = ftell(f);
	rewind(f);

	buffer = (char*)malloc(filelen * sizeof(char));
	fread(buffer, filelen, 1, f);
	printf("%lx\n", filelen);
	for(int i = 0; i < filelen; i ++)
		printf("%hhx ", buffer[i]);
	fclose(f);
	// затирание
	f = fopen(argv[1], "w");
	writebyte(f, 0x55);
	writebyte(f, 0xAA);

	fclose(f);
	return 0;
}


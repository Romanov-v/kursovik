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

    f = fopen(argv[1], "w");
    fprintf(f, "aaaaaa");
    fclose(f);
	// затирание
	gost(argv[1]);
	//writebyte(f, 0x55);
	//writebyte(f, 0xAA);


	return 0;
}


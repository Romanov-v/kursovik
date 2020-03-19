#include <stdio.h>
#include <assert.h>
#include <unistd.h>

#include "Gost.h"
#include "util.h"


int main (int argc, char** argv)
{
	assert(argc > 1);
	assert( (access(argv[1], F_OK)) != -1 && "файла не существует") ;

	// затирание
	//readFileBytes(argv[1]);
	gost(argv[1]);
	//writebyte(f, 0x55);
	//writebyte(f, 0xAA);


	return 0;
}


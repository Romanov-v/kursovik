#include "mashingAlgos.h"
#include <stdlib.h>

int shnauder(char *filename) 
{
    if (filename == NULL) {
        int status = printf("Memory error\n");
        if (status < 0) {
            return 3;
        }
        return 4;
    }
    char newbytes[] = {0xFF, 0x00, rand() % 256, rand() % 256, rand() % 256, rand() % 256, rand() % 256};
    if (algorithm(filename, newbytes, 7) != 0) 
    {
        int status = printf("Error in SHNAUDER method");
        if ( status < 0)
        {
        	return 1;
        }
        return 2;
    }
    return 0;
}
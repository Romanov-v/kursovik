#include "mashingAlgos.h"
#include <stdlib.h>

int navso(char *filename) 
{
    if (filename == NULL) {
        int status = printf("Memory error\n");
        if (status < 0) {
            return 3;
        }
        return 4;
    }

    char newbytes[] = {0x01, 0x07, 0xFF, 0xFF, 0xFF, rand() % 256,};
    if (algorithm(filename, newbytes, 6) != 0)
    {
        int status = printf("Error in NAVSO method");
        if ( status < 0)
        {
        	return 1;
        }
        return 2;
    }
    return 0;
}
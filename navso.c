#include "mashingAlgos.h"
#include <stdlib.h>

int navso(char *filename) 
{
    char newbytes[] = {0x01, 0x7FFFFFF, rand() % 256,};
    if (algorithm(filename, newbytes, 3) != 0) 
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
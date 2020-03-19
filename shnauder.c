#include "mashingAlgos.h"


int shnauder(char * filename)
{
    char newbytes[] = {0xFF, 0x00,  };
    algorithm(filename, newbytes, 2);
    return 0;
}
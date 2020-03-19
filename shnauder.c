#include "mashingAlgos.h"
#include <stdlib.h>

int shnauder(char * filename)
{
    char newbytes[] = {0xFF, 0x00, rand() % 256, rand() % 256, rand() % 256, rand() % 256, rand() % 256};
    algorithm(filename, newbytes, 7);
    return 0;
}
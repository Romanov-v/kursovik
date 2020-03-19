
#include "mashingAlgos.h"

int gost(char * filename)
{
    char newbytes[] = {0x10, 0x20, 0x30};
    algorithm(filename, newbytes, 3);
    return 0;
}


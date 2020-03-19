#include "mashingAlgos.h"
#include <stdlib.h>

int navso(char * filename)
{

    char newbytes[] = {0x01, 0x7FFFFFF, rand() % 256, };
    algorithm(filename, newbytes, 3);
    return 0;
}
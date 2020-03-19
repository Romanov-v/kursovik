#include "mashingAlgos.h"

int navso(char * filename)
{
    char newbytes[] = {0x01, 0x7FFFFFF, };
    algorithm(filename, newbytes, 1);
    return 0;
}
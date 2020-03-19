#include "mashingAlgos.h"

int vsitr(char * filename)
{
    char newbytes[] = {0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xAA};
    algorithm(filename, newbytes, 7);
    return 0;
}
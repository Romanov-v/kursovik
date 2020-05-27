
#include "mashingAlgos.h"

int gost(char * filename)
{
    char newbytes[] = {0x10, 0x20, 0x30};
    if (algorithm(filename, newbytes, 3) != 0){
        printf("Error in GOST method");
        return -1;
    }
    return 0;
}


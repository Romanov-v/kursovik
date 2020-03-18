
#include "Gost.h"

int gost(char * filename) {
    char newbytes[] = {0x70, 0x50, 0x60};
    algorithm(filename, newbytes, 3);
    return 0;
}


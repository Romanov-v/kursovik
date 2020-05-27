#include "mashingAlgos.h"
#include <stdlib.h>

int navso(char *filename) {
    char newbytes[] = {0x01, 0x7FFFFFF, rand() % 256,};
    if (algorithm(filename, newbytes, 3) != 0) {
        printf("Error in NAVSO method");
        return -1;
    }
    return 0;
}
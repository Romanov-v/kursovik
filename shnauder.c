#include "mashingAlgos.h"
#include <stdlib.h>

int shnauder(char *filename) {
    char newbytes[] = {0xFF, 0x00, rand() % 256, rand() % 256, rand() % 256, rand() % 256, rand() % 256};
    if (algorithm(filename, newbytes, 7) != 0) {
        printf("Error in SHNAUDER method");
        return -1;
    }
    return 0;
}
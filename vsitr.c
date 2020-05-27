#include "mashingAlgos.h"

int vsitr(char *filename) {
    char newbytes[] = {0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xAA};
    if (algorithm(filename, newbytes, 7) != 0) {
        printf("Error in VSITR method");
        return -1;
    }
    return 0;
}
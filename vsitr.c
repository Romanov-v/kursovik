#include "mashingAlgos.h"

int vsitr(char *filename) {
    char newbytes[] = {0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xAA};
    if (algorithm(filename, newbytes, 7) != 0) {
        int status = printf("Error in VSITR method");
        if ( status < 0)
        {
        	return 1;
        }
        return 2;
    }
    return 0;
}
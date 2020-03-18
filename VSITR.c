//
// Created by MacBook Pro on 18/03/2020.
//

#include "VSITR.h"

int vsitr(char * filename) {
    char newbytes[] = {0x00, 0xFF, 0xAA};
    algorithm(filename, newbytes, 3);
    return 0;
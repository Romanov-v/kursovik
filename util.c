//
// Created by MacBook Pro on 17/03/2020.
//
#include "util.h"
int writebyte(FILE *f, char* c){
    char buffer_out[1];
    buffer_out[0] = c;
    fwrite(buffer_out, 1, 1, f);
    fclose(f);
    return 0;
}
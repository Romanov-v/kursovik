//
// Created by MacBook Pro on 17/03/2020.
//
#include "util.h"

long int findSize(char file_name[]) {
    // opening the file in read mode
    FILE *fp = fopen(file_name, "r");

    // checking if the file exist or not
    if (fp == NULL) {
        printf("File Not Found!\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    // calculating the size of the file
    long int res = ftell(fp);

    // closing the file
    fclose(fp);

    return res;
}

int writebyte(char *filename, char *c) {
    FILE *f = fopen(filename, "w");
    char buffer_out[1];
    buffer_out[0] = c;
    fwrite(buffer_out, 1, 1, f);
    fclose(f);
    return 0;
}


int algorithm(char *filename, char c[], int sizeOfBytes) {
    int size = findSize(filename);
    readFileBytes(filename);
    for (int j = 0; j < sizeOfBytes; j++) {
        FILE *file = fopen(filename, "wb");
        for (int i = 0; i < size; i++) {
            fseek(file, i, SEEK_SET);
            char tmp = c[j];
            fputs(&tmp, file);
        }
        fclose(file);
        readFileBytes(filename);
    }
}

char *readFileToBytesArray(const char *name) {
    FILE *fl = fopen(name, "r");
    fseek(fl, 0, SEEK_END);
    long len = ftell(fl);
    char *ret = malloc(len);
    memset(ret, 0, sizeof(ret));
    fseek(fl, 0, SEEK_SET);
    fread(ret, 1, len, fl);
    fclose(fl);
    return ret;
}

int readFileBytes(char *filename) {
    char *bytes = readFileToBytesArray(filename);
    int size = findSize(filename);

    bool debug = false;
    if (debug){
        printf("[");
        for(int i = 0; i < size; i ++)
            printf("%x ", bytes[i]);
        printf("]\n");
    }
    return 0;
}

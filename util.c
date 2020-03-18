//
// Created by MacBook Pro on 17/03/2020.
//
#include "util.h"

long int findSize(char file_name[])
{
    // opening the file in read mode
    FILE* fp = fopen(file_name, "r");

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

int writebyte(char * filename, char *c) {
    FILE* f = fopen(filename, "w");
    char buffer_out[1];
    buffer_out[0] = c;
    fwrite(buffer_out, 1, 1, f);
    fclose(f);
    return 0;
}

int algorithm(char * filename, char c[], int sizeOfBytes) {
    FILE *file = fopen(filename, "w");
    int size = findSize(filename);
    printf("{}/n", size);
    readFileBytes(filename);
    char bytes[size];
    fgets(bytes, size, file);
    printf("{%d}\n", size);
    for (int j = 0; j < sizeOfBytes; j++) {
        for (int i = 0; i < size; i++) {
            char newbytes[] = {c[j]};
            fseek(file, i, SEEK_SET);
            fwrite(newbytes, sizeof(newbytes), 1, file);
        }
        readFileBytes(filename);
    }
    fclose(file);
}

int readFileBytes(char* filename) {
    FILE* f = fopen(filename, "r");
    char *buffer;
    long filelen;



    buffer = (char *) malloc(filelen * sizeof(char));
    fread(buffer, filelen, 1, f);

    for (int i = 0; i < filelen; i++)
        printf("%hhx ", buffer[i]);
    printf("\n");
    fclose(f);
    return 0;
}
//
// Created by MacBook Pro on 17/03/2020.
//
#include "util.h"


#define CHUNK 200

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
    for (int j = 0; j < sizeOfBytes; j++) {
        FILE *file = fopen(filename, "wb");
        for (int i = 0; i < size; i++) {
            fseek(file, i, SEEK_SET);
            char tmp = c[j];
            fputs(&tmp, file);
        }
        fclose(file);
    }
}

int atoi(const char* str){
    int num = 0;
    int i = 0;
    bool isNegetive = false;
    if(str[i] == '-'){
        isNegetive = true;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9')){
        num = num * 10 + (str[i] - '0');
        i++;
    }
    if(isNegetive) num = -1 * num;
    return num;
}

struct myString readinput() {
    char *input = NULL;
    char tempbuf[CHUNK];
    size_t inputlen = 0, templen = 0;
    do {
        fgets(tempbuf, CHUNK, stdin);

        templen = strlen(tempbuf);
        input = realloc(input, inputlen + templen);
        strcpy(input + inputlen, tempbuf);
        inputlen += templen;
    } while (templen == CHUNK - 1 && tempbuf[CHUNK - 2] != '\n');

    struct myString out;
    input[inputlen - 1] = 0;
    out.size = inputlen - 1;
    out.data = input;

    return out;
}
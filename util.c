//
// Created by MacBook Pro on 17/03/2020.
//
#include "util.h"


#define CHUNK 200

long int findSize(char file_name[], int *res) {
    // opening the file in read mode
    FILE *fp = fopen(file_name, "r");

    // checking if the file exist or not
    if (fp == NULL) {
        printf("File Not Found!\n");
        return -1;
    }

    int status = fseek(fp, 0L, SEEK_END);
    if (status != 0) {
        printf("fseek error!");
        return -2;
    }

    // calculating the size of the file
    *res = ftell(fp);
    if (res < 0) {
        printf("ftell error!");
        return -3;
    }
    // closing the file
    status = fclose(fp);
    if (status != 0) {
        printf("fclose error!");
        return -4;
    }
    return 0;
}


int algorithm(char *filename, char c[], int sizeOfBytes) {
    int size = 0;
    int status = findSize(filename, &size);
    if (status != 0) {
        printf("findSize error");
        return -1;
    }
    for (int j = 0; j < sizeOfBytes; j++) {
        FILE *file = fopen(filename, "wb");
        if (file == NULL) {
            printf("File Not Found!\n");
            return -2;
        }
        for (int i = 0; i < size; i++) {
            status = fseek(file, i, SEEK_SET);
            if (status != 0) {
                printf("fseek error!");
                return -3;
            }
            char tmp = c[j];
            status = fputs(&tmp, file);
            if (status < 0) {
                printf("fputs error!");
                return -4;
            }
        }
        status = fclose(file);
        if (status != 0) {
            printf("fclose error!");
            return -5;
        }
    }
    return 0;
}

int atoi(const char *str) {
    int num = 0;
    int i = 0;
    bool isNegetive = false;
    if (str[i] == '-') {
        isNegetive = true;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9')) {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    if (isNegetive) num = -1 * num;
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
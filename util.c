//
// Created by MacBook Pro on 17/03/2020.
//
#include "util.h"


#define CHUNK 200

int findSize(char file_name[], int *res)
{
    if (file_name == NULL){
        int status = printf("Memory error!\n");
        if ( status < 0) {
            return 9;
        }
        return 10;
    }

    // opening the file in read mode
    FILE *fp = fopen(file_name, "r");

    // checking if the file exist or not
    if (fp == NULL)
    {
        int status = printf("File Not Found!\n");
        if ( status < 0)
        {
            return 1;
        }
        return 2;
    }

    int status = fseek(fp, 0L, SEEK_END);
    if (status != 0)
    {
        fclose(fp);
        status = printf("fseek error!");
        if ( status < 0)
        {
            return 3;
        }
        return 4;
    }

    // calculating the size of the file
    *res = ftell(fp);
    if (res == NULL)
    {
        status = printf("ftell error!");
        if ( status < 0)
        {
            return 5;
        }
        return 6;
    }
    // closing the file
    status = fclose(fp);
    if (status != 0)
    {
        status = printf("fclose error!");
        if ( status < 0)
        {
            return 7;
        }
        return 8;
    }
    return 0;
}


int algorithm(char *filename, char c[], int sizeOfBytes)
{
    if (filename == NULL){
        int status = printf("Memory error!\n");
        if ( status < 0) {
            return 11;
        }
        return 12;
    }
    int size = 0;
    int status = findSize(filename, &size);
    if (status != 0) {
        status = printf("findSize error");
        if ( status < 0)
        {
            return 1;
        }
        return 2;
    }
    for (size_t j = 0; j < sizeOfBytes; j++)
    {
        FILE *file = fopen(filename, "wb");
        if (file == NULL) {
            status = printf("File Not Found!\n");
            if ( status < 0)
            {
                return 3;
            }
            return 4;
        }
        for (size_t i = 0; i < size; i++)
        {
            status = fseek(file, i, SEEK_SET);
            if (status != 0) {
                fclose(file);
                status = printf("fseek error!");
                if ( status < 0)
                {
                    return 5;
                }
                return 6;
            }
            char tmp = c[j];
            status = fputs(&tmp, file);
            if (status < 0)
            {
                fclose(file);
                status = printf("fputs error!");
                if ( status < 0)
                {
                    return 7;
                }
                return 8;
            }
        }
        status = fclose(file);
        if (status != 0)
        {
            status = printf("fclose error!");
            if ( status < 0)
            {
                return 9;
            }
            return 10;
        }
    }
    return 0;
}

int my_atoi(const char *str, int *num)
{
    if ( str == NULL){
        int status = printf("Memory error\n");
        if (status < 0){
            return 1;
        }
        return 2;
    }
    int i = 0;
    bool isNegetive = false;
    if (str[i] == '-')
    {
        isNegetive = true;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        *num = *num * 10 + (str[i] - '0');
        i++;
    }
    if (isNegetive) *num = -1 * *num;

    return 0;
}

int readinput(struct myString *out)
{
    int status = 0;
    char *input = NULL;
    char tempbuf[CHUNK];
    size_t inputlen = 0, templen = 0;
    do {
        if (fgets(tempbuf, CHUNK, stdin) == NULL)
        {
            int status = printf("fgets error!");
            if ( status < 0)
            {
                return 1;
            }
            return 2;
        }

        templen = strlen(tempbuf);
        input = realloc(input, inputlen + templen);
        if (input == NULL) {
           status = printf("realloc error!");
           if ( status < 0)
           {

            return 3;
           }
            return 4;
        }
        char* c = strcpy(input + inputlen, tempbuf);
        if ( c != input + inputlen){
            free(input);
            status = printf("Memory error");
            if ( status < 0)
            {
                return 5;
            }
            return 6;
        }
        inputlen += templen;
    } while (templen == CHUNK - 1 && tempbuf[CHUNK - 2] != '\n');

    input[inputlen - 1] = 0;
    out->size = inputlen - 1;
    out->data = input;

    return 0;
}
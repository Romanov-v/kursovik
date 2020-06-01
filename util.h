//
// Created by MacBook Pro on 17/03/2020.
//

#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

#include <stdio.h>
#include "stdbool.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
int findSize(char file_name[], int *res);

int algorithm(char *filename, char c[], int sizeOfBytes);

int my_atoi(const char* str, int *num);

struct myString {
    int size;
    char *data;
};

int readinput(struct myString *out);


#endif //UNTITLED_UTIL_H

//
// Created by MacBook Pro on 17/03/2020.
//

#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

#include <stdio.h>
#include "stdbool.h"
#include <string.h>
#include <stdlib.h>

long int findSize(char file_name[]);

int writebyte(char *filename, char *c);

int algorithm(char *filename, char c[], int sizeOfBytes);

int atoi(const char* str);

struct myString {
    int size;
    char *data;
};

struct myString readinput();


#endif //UNTITLED_UTIL_H

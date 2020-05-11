//
// Created by MacBook Pro on 17/03/2020.
//

#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

#include <stdio.h>
#include "stdbool.h"

/* Считает размер файла в байтах
   Вход - имя файла
   Выход - Размер файла в байтах
*/
long int findSize(char file_name[]);

/* 
    Записываем в файл filename байт c
*/
int writebyte(char *filename, char *c);

int algorithm(char *filename, char c[], int sizeOfBytes);

/*
*/
int readFileBytes(char *filename);


#endif //UNTITLED_UTIL_H

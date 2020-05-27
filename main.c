#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "mashingAlgos.h"
#include "util.h"


int main(int argc, char **argv) {
    srand(time(NULL));
    int status = 0;
    printf("write filename you want to be formetted\n");
    struct myString fileNameGetter;
    if (readinput(&fileNameGetter) != 0) {
        printf("Error while reading filename");
        return -1;
    }
    char *filename = fileNameGetter.data;
    assert((access(filename, F_OK)) != -1 && "file not exist\n");

    printf(" Choose one of the ways \n 1 - GOST \n2 - VSITR \n3 - NAVSO \n4 - SHNAIDER \n5 - own bytes\n");
    int g = 0;
    struct myString choosed;
    if (readinput(&choosed) != 0) {
        printf("Error while reading filename");
        return -2;
    }
    if (my_atoi(choosed.data, &g) != 0) {
        printf("Error while converting string to int");
        return -3;
    }
    printf(" Do you relay want to rewrite file {%s}? ( write yes/no to continue) \n", filename);

    struct myString ans;
    if (readinput(&ans) != 0) {
        printf("Error while reading filename");
        return -4;
    }

    if (strcmp("yes", ans.data) != 0) {
        printf("formatting was canceled by user\n");
        return 0;
    }

    switch (g) {
        case 1:
            if (gost(filename) != 0) {
                printf("Gost error!");
                return -5;
            }
            break;
        case 2:
            if (vsitr(filename) != 0) {
                printf("Vsitr error!");
                return -6;
            }
            break;
        case 3:
            if (navso(filename) != 0) {
                printf("Navso error!");
                return -7;
            }
            break;
        case 4:
            if (shnauder(filename) != 0) {
                printf("Shnauder error!");
                return -8;
            }
            break;
        case 5:
            printf("write your byte's values in one line\n");
            struct myString bytes;
            if (readinput(&bytes) != 0) {
                printf("Error while reading filename");
                return -9;
            }
            if (algorithm(filename, bytes.data, bytes.size) != 0) {
                printf("Error in method with users own bytes");
                return -10;
            }
            break;
        default:
            printf("Error! no such varian to choose algorithm\n");
    }
    printf("file {%s} formatted", filename);
    return 0;
}





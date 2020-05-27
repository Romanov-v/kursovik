#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "mashingAlgos.h"
#include "util.h"


int main(int argc, char **argv) {
    srand(time(NULL));
    
    printf("write filename you want to be formetted\n") ;
    struct myString fileNameGetter;
    readinput(&fileNameGetter);
    char * filename = fileNameGetter.data;
    assert((access(filename, F_OK)) != -1 && "file not exist\n");
    
    printf(" Choose one of the ways \n 1 - GOST \n2 - VSITR \n3 - NAVSO \n4 - SHNAIDER \n5 - own bytes\n");
    int g = 0;
    struct myString choosed;
    readinput(&choosed);
    my_atoi(choosed.data, &g);
    printf(" Do you relay want to rewrite file {%s}? ( write yes/no to continue) \n", filename);
    
    struct myString ans;
    readinput(&ans);

    if (strcmp("yes", ans.data) != 0) {
        printf("formatting was canceled by user\n");
        return 0;
    }

    switch (g) {
        case 1:
            gost(filename);
            break;
        case 2:
            vsitr(filename);
            break;
        case 3:
            navso(filename);
            break;
        case 4:
            shnauder(filename);
            break;
        case 5:
            printf("write your byte's values in one line\n");
            struct myString bytes;
            readinput(&bytes);
            algorithm(filename, bytes.data, bytes.size);
            break;
        default:
            printf("Error! no such varian to choose algorithm\n");
    }
    printf("file {%s} formatted", filename);
    return 0;
}





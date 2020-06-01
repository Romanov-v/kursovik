#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "mashingAlgos.h"
#include "util.h"


int main(int argc, char **argv) 
{
    srand(time(NULL));
    int status = printf("write filename you want to be formetted\n");
    if ( status < 0)
    {
        return 1;
    }
    struct myString fileNameGetter;
    if (readinput(&fileNameGetter) != 0) 
    {
        status = printf("Error while reading filename");
        if ( status < 0)
        {
            return 2;
        }
        return 3;
    }
    char *filename = fileNameGetter.data;
    assert((access(filename, F_OK)) != -1 && "file not exist\n");

     status = printf(" Choose one of the ways \n 1 - GOST \n2 - VSITR \n3 - NAVSO \n4 - SHNAIDER \n5 - own bytes\n");
    if ( status < 0)
    {
        return 4;
    }
    int g = 0;
    struct myString choosed;
    if (readinput(&choosed) != 0) 
    {
        status = printf("Error while reading filename");
        if ( status < 0)
        {
            return 5;
        }
        return 6;
    }
    if (my_atoi(choosed.data, &g) != 0) 
    {
       status = printf("Error while converting string to int");
       if ( status < 0)
       {
        return 7;
       }
        return 8;
    }
    status = printf(" Do you relay want to rewrite file {%s}? ( write yes/no to continue) \n", filename);
    if ( status < 0)
    {
        return 9;
    }
    struct myString ans;
    if (readinput(&ans) != 0) 
    {
        status = printf("Error while reading filename");
        if (status < 0)
        {
            return 10;
        }
        return 11;
    }

    if (strcmp("yes", ans.data) != 0) 
    {
        status = printf("formatting was canceled by user\n");
        if ( status < 0)
        {
            return 12;
        }
        return 0;
    }

    switch (g) 
    {
        case 1:
            if (gost(filename) != 0) 
            {
                status = printf("Gost error!");
                if ( status < 0)
                {
                    return 13;
                }
                return 14;
            }
            break;
        case 2:
            if (vsitr(filename) != 0) 
            {
                status = printf("Vsitr error!");
                if ( status < 0)
                {
                    return 15;
                }
                return 16;
            }
            break;
        case 3:
            if (navso(filename) != 0) 
            {
                status = printf("Navso error!");
                if ( status < 0)
                {
                    return 17;
                }
                return 18;
            }
            break;
        case 4:
            if (shnauder(filename) != 0) 
            {
                status = printf("Shnauder error!");
                if ( status < 0)
                {
                    return 19;
                }
                return 20;
            }
            break;
        case 5:
            status = printf("write your byte's values in one line\n");
            if ( status < 0)
            {
                return 21;
            }
            struct myString bytes;
            if (readinput(&bytes) != 0)
            {
                status = printf("Error while reading filename");
                if ( status < 0)
                {
                    return 22;
                }
                return 23;
            }
            if (algorithm(filename, bytes.data, bytes.size) != 0) 
            {
                status = printf("Error in method with users own bytes");
                if ( status < 0)
                {
                    return 24;
                }
                return 25;
            }
            break;
        default:
            status = printf("Error! no such varian to choose algorithm\n");
            if ( status < 0)
            {
                return 26;
            }
    }
    printf("file {%s} formatted", filename);
    return 0;
}





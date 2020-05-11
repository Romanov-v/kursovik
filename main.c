#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "mashingAlgos.h"
#include "util.h"
int main (int argc, char** argv)
{
    srand(time(NULL));
    assert(argc > 1);
    assert( (access(argv[1], F_OK)) != -1 && "файла не существует") ;

        printf("Do you want to erase information with your data? \n 1 - yes 2 - no \n");
        int h;
        scanf("%d", &h);
        if (h == 1) {
            printf("values");
            char o = 0;
            char j = 0;
            char f = 0;
            scanf("%c %c %c", &o, &j, &f);
                char newBytes[] = {o, j, f};
                algorithm(argv[1], newBytes, 3);
                return 0;

        } else if (h > 1)
        {
            printf(" Choose one of the ways \n 1 - GOST 2 - VSITR 3 - NAVSO 4 - SHNAIDER \n");
            int g;
            scanf("%d", &g);
            if (g == 4) {
                shnauder(argv[1]);
            } else if (g == 1) {
                gost(argv[1]);
            } else if (g == 2) {
                vsitr(argv[1]);
            } else {
                navso(argv[1]);
            }
            return 0;
    }
    return 0;
}





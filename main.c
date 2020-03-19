#include <stdio.h>
#include <assert.h>
#include <unistd.h>

#include "Gost.h"
#include "util.h"


int main (int argc, char** argv)
{
    assert(argc > 1);
    assert( (access(argv[1], F_OK)) != -1 && "файла не существует") ;

    FILE * f;

    f = fopen(argv[1], "w");
    fprintf(f, "aaaaaa");
    fclose(f);
    // затирание
    gost(argv[1]);
    //writebyte(f, 0x55);
    //writebyte(f, 0xAA);

    int user(int argc, char** argv)
    {

        printf("Do you want to erase information with your data? \n 1 - yes 2 - no \n");

        int h;
        scanf("%d", &h);
        if (h == 1) {
            printf("Введте свои значения");
            int o = 0;
            int j = 0;
            int f = 0;
            scanf("%d %d %d", &o, &j, &f);
            int user(char *filename);
            {
                char newbytes[] = {o, j, f};
                algorithm(argv[1], newbytes, 3);
                return 0;
            }

        } else if (h > 1)
        {
            printf(" Choose one of the ways \n 1 - GOST 2 - VSITR 3 - NAVSO 4 - SHNAIDER \n");
            int g;
            scanf("%d", &g);
            if (g > 4) {
                int shnaider(char *filename);
            } else if (g < 1) {
                int gost(char *filename);

            } else if (g == 2) {
                int vsitr(char *filename);

            } else {
                int navso(char *filename);
            }
            return 0;


        }
    }


    return 0;
}





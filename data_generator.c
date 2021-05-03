#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int dataSize) {
    int x;
    int i;
    FILE* fp = fopen("dataset1.txt", "w");
    srand(time(NULL));
    for (i = 0; i < dataSize; i++)     {
        x = rand() % 10000000;
        fprintf(fp, "%d\n", x);
    }
    fclose(fp);
    return 0;
}

int randstring(int dataSize) {
    int x;
    int i, j;
    FILE* fp = fopen("dataset2.txt", "w");
    srand(time(NULL));
    for (i = 0; i < dataSize; i++)     {
        for (j = 0; j < 100; j++)         {
            x = rand() % ('z' - 'A' + 1);
            while (x >= 26 && x <= 32)             {
                x = rand() % ('z' - 'A');
            }
            fprintf(fp, "%c", 'A' + x);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int dataSize) {
    int x;
    int i;
    FILE* fp = fopen("dataset1.txt", "w");
    srand(time(NULL));
    for (i = 0; i < dataSize; i++) {
        x = rand() % 10000000;
        fprintf(fp, "%d\n", x);
    }
    fclose(fp);
    return 0;
}
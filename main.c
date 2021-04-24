#include "quicksort.h"
#include "data_generator.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int dataSize;
    int i = 0;
    int nums[1000000];
    printf("input data size:\n");
    scanf("%d", &dataSize);
    randint(dataSize);
    FILE* fp = fopen("dataset1.txt", "r");
    while (fscanf(fp, "%d", &nums[i++]) != EOF) {}
    quicksort(nums, 0, dataSize - 1);
    for (i = 0; i < dataSize; i++) {
        printf("%d\n", nums[i]);
    }
    fclose(fp);
    return 0;
}
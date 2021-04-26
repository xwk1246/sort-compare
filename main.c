#include "quicksort.h"
#include "data_generator.h"
#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define DATASIZE 1000000

double getdiff(struct timeval start, struct timeval end) {
    return (end.tv_usec - start.tv_usec);
}
int main() {
    int i = 0;
    int nums[DATASIZE];
    struct timeval start;
    struct timeval end;

    randint(1000000);
    FILE* fp = fopen("dataset1.txt", "r");
    while (fscanf(fp, "%d", &nums[i++]) != EOF) {}

    gettimeofday(&start, NULL);
    quicksort(nums, 0, DATASIZE - 1);
    gettimeofday(&end, NULL);
    printf("quicksort finished in %f\n", getdiff(start, end) / 1000);

    gettimeofday(&start, NULL);
    mergesort(nums, 0, DATASIZE - 1);
    gettimeofday(&end, NULL);
    printf("mergesort finished in %f\n", getdiff(start, end) / 1000);
    fclose(fp);
    return 0;
}
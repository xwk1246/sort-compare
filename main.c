#include "quicksort.h"
#include "data_generator.h"
#include "mergesort.h"
#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#define DATASIZE 1000000

double getdiff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
}
int main() {
    int i;
    int j;
    static int nums_tmp[DATASIZE];
    static char* string_line[DATASIZE];
    struct timeval start;
    struct timeval end;
    int n;
    printf("Enter number of tests:\n");
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
        printf("--------------------------------\n");
        printf("test %d\n", j + 1);
        printf("--------------------------------\n");
        printf("generating dataset1...\n");
        randint(1000000);
        printf("done\n");
        printf("generating dataset2...\n");
        randstring(1000000);
        printf("done\n");

        FILE* fp = fopen("dataset1.txt", "r");
        i = 0;
        while (fscanf(fp, "%d", &nums_tmp[i++]) != EOF)
            ;
        fclose(fp);
        int* nums = (int*)malloc(sizeof(int) * DATASIZE);
        memcpy(nums, nums_tmp, sizeof(int) * DATASIZE);
        fp = fopen("dataset2.txt", "r");

        gettimeofday(&start, NULL);
        quickSort(nums, 0, DATASIZE - 1);
        gettimeofday(&end, NULL);
        printf("quicksort finished in %.2f ms\n", getdiff(start, end) / 1000);

        memcpy(nums, nums_tmp, sizeof(int) * DATASIZE);
        gettimeofday(&start, NULL);
        mergeSort(nums, 0, DATASIZE - 1);
        gettimeofday(&end, NULL);
        printf("mergesort finished in %.2f ms\n", getdiff(start, end) / 1000);

        memcpy(nums, nums_tmp, sizeof(int) * DATASIZE);
        gettimeofday(&start, NULL);
        heapSort(nums, DATASIZE);
        gettimeofday(&end, NULL);
        printf("heapsort finished in %.2f ms\n", getdiff(start, end) / 1000);
        free(nums);
    }
    printf("---------------end--------------\n");

    return 0;
}
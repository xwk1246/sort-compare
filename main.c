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

void readdata(int* nums_tmp, char** string_line) {
    int i;
    char* tmpLine;
    FILE* fp;
    fp = fopen("dataset1.txt", "r");
    i = 0;
    while (fscanf(fp, "%d", &nums_tmp[i++]) != EOF)
        ;
    fclose(fp);

    fp = fopen("dataset2.txt", "r");
    i = 0;
    while (fscanf(fp, "%s", tmpLine = (char*)malloc(sizeof(char) * 102)) != EOF) {
        string_line[i++] = tmpLine;
    }


}

int main() {
    int i;
    int j;
    static int nums_tmp[DATASIZE];
    static char* string_line[DATASIZE];
    char* tmpLine;
    struct timeval start;
    struct timeval end;
    int n;
    FILE* fp;
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

        readdata(nums_tmp, string_line);

        int* nums = (int*)malloc(sizeof(int) * DATASIZE);
        memcpy(nums, nums_tmp, sizeof(int) * DATASIZE);
        char** strings = (char**)malloc(sizeof(char*) * DATASIZE + 1);
        memcpy(strings, string_line, sizeof(char*) * DATASIZE + 1);
        gettimeofday(&start, NULL);
        quickSort(nums, 0, DATASIZE - 1);
        quickSort_str(strings, 0, DATASIZE - 1);
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
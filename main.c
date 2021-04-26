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
FILE* readfile(int* nums_tmp, char** string_list) {
    int i;
    char* current_string_ptr;
    char string_tmp[101];
    FILE* fp = fopen("dataset1.txt", "r");
    i = 0;

    while (fscanf(fp, "%d", &nums_tmp[i++]) != EOF) {}
    fclose(fp);
    i = 0;
    FILE* fp2 = fopen("dataset2.txt", "r");
    while (fscanf(fp2, "%s", string_tmp) != EOF) {
        current_string_ptr = (char*)malloc(sizeof(char) * 101);
        strcpy(current_string_ptr, string_tmp);
        string_list[i] = current_string_ptr;
        i++;
    }
    fclose(fp2);
}

int main() {
    int i;
    int j;
    int nums_tmp[DATASIZE];
    char* string_list[DATASIZE];
    struct timeval start;
    struct timeval end;
    int n;
    printf("Enter number of tests:\n");
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
        randint(1000000);
        randstring(1000000);

        readfile(nums_tmp, string_list);

        int* nums = (int*)malloc(sizeof(int) * DATASIZE);
        printf("--------------------------------\n");
        printf("test %d\n", j + 1);
        printf("--------------------------------\n");

        memcpy(nums, nums_tmp, sizeof(int) * DATASIZE);
        gettimeofday(&start, NULL);
        quicksort(nums, 0, DATASIZE - 1);
        gettimeofday(&end, NULL);
        printf("quicksort finished in %.2f ms\n", getdiff(start, end) / 1000);

        memcpy(nums, nums_tmp, sizeof(int) * DATASIZE);
        gettimeofday(&start, NULL);
        mergesort(nums, 0, DATASIZE - 1);
        gettimeofday(&end, NULL);
        printf("mergesort finished in %.2f ms\n", getdiff(start, end) / 1000);

        memcpy(nums, nums_tmp, sizeof(int) * DATASIZE);
        gettimeofday(&start, NULL);
        heapsort(nums, DATASIZE);
        gettimeofday(&end, NULL);
        printf("heapsort finished in %.2f ms\n", getdiff(start, end) / 1000);
        free(nums);
    }
    printf("---------------end--------------\n");
    for (j = 0; j < 1000000; j++) {
        printf("%s", string_list[j]);
    }

    return 0;
}
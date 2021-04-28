#include <string.h>
void merge(int number[], int left, int mid, int right) {
    int i = 0;
    int j = 0;
    int cnt;
    int tmp;
    int arr1Len = mid - left + 1;
    int arr2Len = right - mid;
    int arr1[arr1Len];
    int arr2[arr2Len];
    for (cnt = 0; cnt < arr1Len; cnt++) {
        arr1[cnt] = number[left + cnt];
    }
    for (cnt = 0; cnt < arr2Len; cnt++) {
        arr2[cnt] = number[mid + 1 + cnt];
    }
    while (arr1Len && arr2Len) {
        if (arr1[i] <= arr2[j]) {
            number[left++] = arr1[i++];
            arr1Len--;
        }
        else if (arr1[i] > arr2[j]) {
            number[left++] = arr2[j++];
            arr2Len--;
        }
    }
    while (arr1Len > 0) {
        number[left++] = arr1[i++];
        arr1Len--;
    }
    while (arr2Len > 0) {
        number[left++] = arr2[j++];
        arr2Len--;
    }
}

void mergeSort(int number[], int left, int right) {
    int mid;
    int* tmp;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(number, left, mid);
        mergeSort(number, mid + 1, right);
        merge(number, left, mid, right);
    }
}
void merge_str(char* string[], int left, int mid, int right) {
    int i = 0;
    int j = 0;
    int cnt;
    int tmp;
    int arr1Len = mid - left + 1;
    int arr2Len = right - mid;
    char* arr1[arr1Len];
    char* arr2[arr2Len];
    for (cnt = 0; cnt < arr1Len; cnt++) {
        arr1[cnt] = string[left + cnt];
    }
    for (cnt = 0; cnt < arr2Len; cnt++) {
        arr2[cnt] = string[mid + 1 + cnt];
    }
    while (arr1Len && arr2Len) {
        if (strcmp(arr1[i], arr2[j]) <= 0) {
            string[left++] = arr1[i++];
            arr1Len--;
        }
        else if (strcmp(arr1[i], arr2[j]) > 0) {
            string[left++] = arr2[j++];
            arr2Len--;
        }
    }
    while (arr1Len > 0) {
        string[left++] = arr1[i++];
        arr1Len--;
    }
    while (arr2Len > 0) {
        string[left++] = arr2[j++];
        arr2Len--;
    }
}
void mergeSort_str(char* string[], int left, int right) {
    int mid;
    int* tmp;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort_str(string, left, mid);
        mergeSort_str(string, mid + 1, right);
        merge_str(string, left, mid, right);
    }
}
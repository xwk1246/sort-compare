#include <string.h>

void quickSort(int number[], int left, int right) {
    int i = left;
    int j = right;
    int tmp;
    int pivot = number[right];
    int current = 0;
    if (j - i > 0 && i >= 0) {
        while (i < j) {
            while (number[i] <= pivot && i < j) {
                i++;
            }
            while (number[j] >= pivot && i < j) {
                j--;
            }
            tmp = number[i];
            number[i] = number[j];
            number[j] = tmp;
        }
        tmp = number[i];
        number[i] = number[right];
        number[right] = tmp;
        quickSort(number, left, i - 1);
        quickSort(number, i + 1, right);
    }
}
void quickSort_str(char* string[], int left, int right) {
    int i = left;
    int j = right;
    char* tmp;
    char* pivot = string[right];
    int current = 0;
    if (j - i > 0 && i >= 0) {
        while (i < j) {
            while (strcmp(string[i], pivot) <= 0 && i < j) {
                i++;
            }
            while (strcmp(string[j], pivot) >= 0 && i < j) {
                j--;
            }
            tmp = string[i];
            string[i] = string[j];
            string[j] = tmp;
        }
        tmp = string[i];
        string[i] = string[right];
        string[right] = tmp;
        quickSort_str(string, left, i - 1);
        quickSort_str(string, i + 1, right);
    }
}
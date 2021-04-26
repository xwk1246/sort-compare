void quicksort(int number[], int left, int right) {
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
        quicksort(number, left, i - 1);
        quicksort(number, i + 1, right);
    }

}
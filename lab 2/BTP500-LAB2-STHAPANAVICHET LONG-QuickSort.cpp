//
// Created by sthap on 1/22/2024.
//
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int* array, int n, int start = 0) {
    if(start >= n - 1) return;
    int pivotIndex = start;
    for(int i = start; i < n-1; i++) {
        if (array[i] < array[n - 1]) {
            swap(array[pivotIndex], array[i]);
            pivotIndex++;
        }
    }
    swap(array[pivotIndex], array[n - 1]);
    quickSort(array, pivotIndex, start);
    quickSort(array, n, pivotIndex + 1);
}
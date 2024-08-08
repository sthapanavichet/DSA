//
// Created by sthap on 1/22/2024.
//
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertSort(int* array, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0; j--) {
            if(array[j] < array[j-1]) {
                swap(array[j], array[j-1]);
            }
        }
    }
}
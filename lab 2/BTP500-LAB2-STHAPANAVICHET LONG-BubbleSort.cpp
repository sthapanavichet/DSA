//
// Created by sthap on 1/22/2024.
//
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int* array, int n) {
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}
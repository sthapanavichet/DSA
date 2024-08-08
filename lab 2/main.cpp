#include <iostream>
#include <limits>

using namespace std;
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

void insertSort(int* array, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0; j--) {
            if(array[j] < array[j-1]) {
                swap(array[j], array[j-1]);
            }
        }
    }
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

int main() {
    int arr1[] = {13, 63, 55, 35, 25, 34, 14, 5, 52, 97};
    int arr2[] = {20, 69, 86, 3, 24, 91, 17, 78, 88, 90};
    int arr3[] = {66, 33, 52, 9, 99, 11, 1, 47, 87, 86};
    int arr4[] = {30, 24, 90, 33, 59, 86, 54, 84, 98, 25};
    int arr5[] = {17, 68, 93, 78, 72, 56, 75, 62, 71, 94};
    int* arrays[] = {arr1, arr2, arr3, arr4, arr5};
    cout << "unsorted arrays" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "arr"<< i <<": ";
        for(int j = 0; j < 10; j++) {
            std::cout << arrays[i][j] << ", ";
        }
        cout << endl;
    }
    char choice;
    std::cout << "Enter I for Insertion Sort, B for Bubble Sort, Q for Quick Sort: ";
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(choice == 'I' or choice == 'i') for (int i = 0; i < 5; i++) insertSort(arrays[i], 10);
    else if(choice == 'B' or choice == 'b') for (int i = 0; i < 5; i++) bubbleSort(arrays[i], 10);
    else if(choice == 'Q' or choice == 'q') for(int i = 0; i < 5; i++) quickSort(arrays[i], 10);
    for(int i = 0; i < 5; i++) {
        cout << "arr"<< i <<": ";
        for(int j = 0; j < 10; j++) {
            std::cout << arrays[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}

//
// Created by sthap on 2/25/2024.
//
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    // Create L <- A[start..mid] and M<- A[mid+1..end]
    int n1 = mid - start + 1;
    int n2 = end - mid;
    //Create temporary arrays
    vector<int> arr1(n1), arr2(n2);
    //Copy data to temproary arrays
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = start;
    // Until we reach either end of either arr1 or arr2, pick larger among
    // elements arr1 and arr2 and place them in the correct position at arr[start..end]
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either arr1 or arr2,
    // pick up the remaining elements and put in arr[start..end]
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& array, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        // Sort first and second halves
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        // Merge the sorted halves
        merge(array, start, mid, end);
    }
}
vector<int> generateRandomArray(int size) {
    std::vector<int> arr;
    for (int i = 0; i < size; ++i) {
        arr.push_back(rand() % 100);  // Random values between 0 and 99
    }
    return arr;
}

int main() {
    srand(time(0)); //used for random generation
    int testcases [4] = {5,10,20,50};
    std::vector<int> arr ;

    std::cout << "Original array: ";
    for (int i = 0; i < 4; i++) {
        cout << "Testing with " << testcases[i] << " nodes" << endl;

        vector<int> arr = generateRandomArray(testcases[i]);

        std::cout << "Unsorted Array: ";
        for (int num : arr) {
            std::cout << num << " ";
        }

        int size = arr.size();

        // Perform Merge Sort
        mergeSort(arr, 0, size - 1);

        std::cout << "\nSorted array: ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << "\n\n";
    }



    return 0;
}
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono> // Include chrono for timing

using namespace std;
using namespace std::chrono; // Use the namespace for chrono

void selectionSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;  // Random values between 0 and 99
    }
    return arr;
}

int main() {
    srand(time(0)); // Seed for random number generation

    int testCases[] = {5, 10, 20, 50};

    for (int test : testCases) {
        cout << "Testing with " << test << " nodes" << endl;

        vector<int> arr = generateRandomArray(test);

        cout << "Unsorted Array: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;

        // Start timing
        auto start = high_resolution_clock::now();

        // Perform Selection Sort
        selectionSort(arr);

        // Stop timing
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Sorted Array: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << "\nTime taken: " << duration.count() << " microseconds\n\n";
    }

    return 0;
}

void runTest(int size) {
    int arr[size];

    // worse case
    for (int i = 0; i < size; ++i)
        arr[i] = size - i;

    cout << "array with " << size << " nodes: ";
    printArray(arr, size);

    // Measure time taken by heapSort
    auto start = chrono::high_resolution_clock::now();
    heapSort(arr, size);
    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program in nanoseconds
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-6; // convert to milliseconds

    cout << "Sorted array with " << size << " nodes: ";
    printArray(arr, size);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(6);
    cout << " milliseconds" << endl;
}
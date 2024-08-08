#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
using namespace std;

void heapify(int arr[], int n, int root)
{
    int largest = root;
    int lc = 2 * root + 1; // left-child = 2 * root + 1
    int rc = 2 * root + 2; // right-child = 2 * root + 2

    // If left child is larger than root
    if (lc < n)
        if(arr[lc] > arr[largest])
            largest = lc;

    // If right child is larger than largest
    if (rc < n)
        if(arr[rc] > arr[largest])
            largest = rc;

    // If largest is not root
    if (largest != root) {
        swap(arr[root], arr[largest]);

        // heapify sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // initial heapify
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
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

int main() {
    // Test cases
    runTest(5);
    runTest(10);
    runTest(20);
    runTest(50);

    return 0;
}


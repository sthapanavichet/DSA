#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <unistd.h>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

void merge(int arr[], int start, int mid, int end) {
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
void mergeSort(int array[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        // Sort first and second halves
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        // Merge the sorted halves
        merge(array, start, mid, end);
    }
}


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

int main() {
    int size[] = {5, 10, 20, 50};
    int choice = 0;
    cout << "1: Selection Sort" << endl << "2: Heap Sort" << endl << "3: Merge Sort" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    for(int i = 0; i < 4; i++) {
        int arr[size[i]];

        // worse case
        for (int j = 0; j < size[i]; ++j)
            arr[j] = size[i] - j;

        cout << "array with " << size[i] << " nodes: ";
        printArray(arr, size[i]);
        auto start = chrono::high_resolution_clock::now();
        auto end = chrono::high_resolution_clock::now();
        double time_taken;
        sleep(1);
        switch(choice) {
            case 1:
                // Measure time taken by heapSort
                start = chrono::high_resolution_clock::now();
                selectionSort(arr, size[i]);
                end = chrono::high_resolution_clock::now();

                // Calculating total time taken by the program in nanoseconds
                time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

                time_taken *= 1e-6; // convert to milliseconds

                cout << "Sorted array with " << size[i] << " nodes: ";
                printArray(arr, size[i]);
                cout << "Time taken by program is : " << fixed
                     << time_taken << setprecision(6);
                cout << " milliseconds" << endl;
                break;
            case 2:
                start = chrono::high_resolution_clock::now();
                heapSort(arr, size[i]);
                end = chrono::high_resolution_clock::now();

                // Calculating total time taken by the program in nanoseconds
                time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

                time_taken *= 1e-6; // convert to milliseconds

                cout << "Sorted array with " << size[i] << " nodes: ";
                printArray(arr, size[i]);
                cout << "Time taken by program is : " << fixed
                     << time_taken << setprecision(6);
                cout << " milliseconds" << endl;
                break;
            case 3:
                start = chrono::high_resolution_clock::now();
                mergeSort(arr, 0, size[i] - 1);
                end = chrono::high_resolution_clock::now();
                // Calculating total time taken by the program in nanoseconds
                time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-6; // convert to milliseconds

                cout << "Sorted array with " << size[i] << " nodes: ";
                printArray(arr, size[i]);
                cout << "Time taken by program is : " << fixed
                     << time_taken << setprecision(6);
                cout << " milliseconds" << endl;
                break;

        }
    }
    return 0;
}

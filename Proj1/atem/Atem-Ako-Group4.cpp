#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include <iomanip>

using namespace std;
using namespace chrono;
// Counter variable to track the number of operations
int mergeSortOperations = 0;

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
		// Increment the counter for each comparison
		mergeSortOperations++;
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
		// Increment the counter for each element assignment
		mergeSortOperations++;
	}
	while (j < n2) {
		arr[k] = arr2[j];
		j++;
		k++; 
		// Increment the counter for each element assignment
		mergeSortOperations++;
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
void runTest(vector<int>& arr, const string& testName) {
	cout << "\nUnsorted array for " << testName << ": ";
	for (int num : arr) {
		cout << num << " ";
	}
	cout << "\n\n";

	mergeSortOperations = 0; // Reset the counter for each test

	auto start = high_resolution_clock::now();
	mergeSort(arr, 0, arr.size() - 1);
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program in nanoseconds
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-6; // convert to milliseconds
       
	cout << "\nSorted array for " << testName << ": ";
	for (int num : arr) {
		cout << num << " ";
	}
	cout << "\n\n";
	cout << "Time taken by program is : " << fixed
		<< time_taken << setprecision(6);
	cout << " milliseconds" << endl;
	// Print the number of operations
	cout << "Number of operations for " << testName << ": " << mergeSortOperations << endl;
}



int main() {
	std::vector<int> arr5 = { 5, 4, 3, 2, 1 };
	std::vector<int> arr10 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::vector<int> arr20 = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::vector<int> arr50 = { 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	std::cout << "\n\n";

	runTest(arr5, "5 nodes");
	runTest(arr10, "10 nodes");
	runTest(arr20, "20 nodes");
	runTest(arr50, "50 nodes");

		return 0;
	}

	



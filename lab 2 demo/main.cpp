/******************************************************************************
Problem Statememnt :: BINARY SEARCH
this algorithum is used when the array is sorted.

 steps to solve this problem :
1. find mid values of the array (start-end/2)
2. check if mid values == x (no to be searched)
    I. if arr[mid] ==x return arr[mid]
    II. if arr[mid] > x then end = mid-1
    III. if arr[mid] < x then start = mid+1.
    if not found return -1
*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

/*===========================================
     FUNCTION FOR Binary search
============================================*/
/**************** Iteration *******************/

//sorted array only
int BinarySearch(int array[], int key, int start, int end)
{
    if(start > end) return -1;
    // declare and initialize start and end index of an array
    cout << "Given array is ";
    for (int i = 0; i <= end; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl << " Key to search is  " << key << endl;
    int mid = (start + end) / 2;       //find mid values
    cout << "Start = " << start;
    cout << " End = " << end;
    cout << " Mid = " << mid << endl;
    int result = -1;
    //check if mid ==key
    if (array[mid] == key) {
        return mid;
    }
        //check if mid > key
    else if (array[mid] > key) {
        return BinarySearch(array, key, start, mid-1);
    }
        //check if mid < key
    else if (array[mid] < key) {
        return BinarySearch(array, key, mid+1, end);
    }
    return result;
};

int main()
{
    //declare and initialize a sorted array for 5 nodes
    int array[] = { 11,22,33,44,55};

    //length of the array
    int n = sizeof(array) / sizeof(array[0]);

    // number to be searched for unsuccessful search
    int key ;
    cout << "Enter the search key" << endl;
    cin >> key;

    //Note the start time
    auto startT = chrono::system_clock::now();
    time_t start_time = chrono::system_clock::to_time_t(startT);

    cout << "Started computation at " << std::ctime(&start_time) << endl;


    //call the function
    int result = BinarySearch(array, key, 0, n);

    if (result == -1)
        cout << "Key not found!" << endl;
    else
        cout << "Key is present at index " << result << endl;

    //Calculate the end time here after completing the algorithm
    auto endT = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = endT - startT;
    time_t end_time = chrono::system_clock::to_time_t(endT);

    cout << "Finished computation at " << ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s" << endl;


    return 0;
}

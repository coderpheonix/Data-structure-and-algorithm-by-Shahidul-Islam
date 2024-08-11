#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, minIndex;

    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted array
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int ) {
    for (int i = 0; i <n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Unsorted array: \n";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: \n";
    printArray(arr, n);

    return 0;
}


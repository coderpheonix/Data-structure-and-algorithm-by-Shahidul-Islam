#include <iostream>  // Include the input-output stream header

using namespace std; // Use the standard namespace

// Function to merge two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Calculate the size of the first subarray
    int n2 = right - mid;     // Calculate the size of the second subarray

    int L[n1], R[n2];         // Create temporary arrays for the two subarrays

    // Copy data to temporary array L[] from the left subarray
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // Copy data to temporary array R[] from the right subarray
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Initial indexes for the left (i), right (j) subarrays and merged subarray (k)
    int i = 0, j = 0, k = left;

    // Merge the temporary arrays back into arr[left..right]
    while (i < n1 && j < n2) {  // Continue while there are elements in both subarrays
        if (L[i] <= R[j]) {     // If the current element of L[] is smaller or equal to R[]
            arr[k] = L[i];      // Place L[i] into the merged array
            i++;                // Move to the next element in L[]
        } else {
            arr[k] = R[j];      // Place R[j] into the merged array
            j++;                // Move to the next element in R[]
        }
        k++;                    // Move to the next position in the merged array
    }

    // Copy any remaining elements of L[] into arr[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[] into arr[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort on arr[] from index 'left' to 'right'
void mergeSort(int arr[], int left, int right) {
    if (left < right) {  // Check if the array has more than one element
        int mid = (left +right) / 2;  // Calculate the middle point to split the array

        // Recursively sort the first half
        mergeSort(arr, left, mid);

        // Recursively sort the second half
        mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82,81, 10};  // Initialize the array to be sorted
    int arr_size = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements in the array

    mergeSort(arr, 0, arr_size - 1);  // Call mergeSort on the entire array

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arr_size; i++)  // Iterate through the sorted array
        cout << arr[i] << " ";  // Print each element followed by a space
    cout << endl;  // Print a newline at the end

    return 0;  // Return 0 to indicate successful execution
}


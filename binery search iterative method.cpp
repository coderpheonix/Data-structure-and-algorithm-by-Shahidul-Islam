#include<iostream>

using namespace std;

int array[15], i, x, n;

int BinarySearch(int low, int high)
{
    while(low<=high)
    {



    int mid=(low+high)/2;

    if (array[mid]==x)
    {
        return mid;
    }
    else if (array[mid] >x)
    {
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }
   return -1;
    }
}


int main() {
    cout << "Input the size of array: ";
    cin >> n;

    cout << "Input the values of the array (in sorted order): ";
    for (i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "Input the value you want to search: ";
    cin >> x;

    // Call the function
    int result = BinarySearch(0, n - 1);
    if (result == -1) {
        cout << "The value is not found in the array.";
    } else {
        cout << "The value is found at index: " << result;
    }

    return 0;
}

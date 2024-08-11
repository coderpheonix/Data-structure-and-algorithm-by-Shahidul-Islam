#include<iostream>
using namespace std;
int array[15],i,x,n;
int BinarySearch(int low , int high)
{
    if (low >high)
    {
        return -1;
    }
    else
    {
        int mid = (low+high)/2;
        if (array[mid]==x)
        {
            return mid;
        }
        else if (array[mid]>x)
        {
            return BinarySearch(low, n-1);
        }
        else
        {
            return BinarySearch(mid+1,high);
        }
    }
}
int main ()
{
cout<<"Input the size of the element: " ;
cin>> n;
cout<<"Input the value of the array : ";
for (i=0; i<n;i++)
{
    cin>>array[i];
}
cout<<"Input the value you want to search : ";
cin>>x;
 int result = BinarySearch(0, n - 1);
    if (result == -1) {
        cout << "The value is not found in the array.";
    } else {
        cout << "The value is found at index: " << result;
    }
return 0;
}

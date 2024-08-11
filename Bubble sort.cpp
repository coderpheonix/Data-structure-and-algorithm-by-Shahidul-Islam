#include<iostream>

using namespace std;


int main ()

{
    int array[15],i, j, n;

    cout<<"input the size of array : ";
    cin>>n;

    // for getting the input form the user
    cout<<"Input the unsorted element : ";
     for (i=0;i<n;i++)
     {
         cin>> array[i];
     }

    // for printing the given value

    cout<<"The given unsorted element is : ";
     for (i=0;i<n;i++)
     {
         cout<< array[i]<< " ";
     }
     cout<<endl;
// for sorting the element

for (i=0;i<n;i++)
{
    for( int j=i+1;j<n;j++)
    {
        if(array[i]>array[j])
        {
           int tem=array[i];
            array[i]=array[j];
            array[j]=tem;
        }
    }
}

// FOR PRINTING THE SORTED ELEMENTS
cout<<"The sorted element Is : ";

for(i=0;i<n;i++)
{
    cout<<array[i]<<" ";
}



    return 0;
}

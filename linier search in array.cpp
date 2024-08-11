

#include<iostream>

using namespace std;


int main ()


{
    int array[10], i, x,n;

    cout<<"Input the size of array : ";
    cin>> n;
    cout<<"Input the element of the array :" ;

    for(i=0;i<n;i++)
    {
    cin>>array[i];
    }
    // print the given in put

    for (i=0;i<n;i++)
    {
        cout<<array[i]<<endl;
    }


    // for search a value_type

    cout<<"Input a value you want to search:"<<endl;
    cin>> x;


    for (i=0;i<n;i++)
    {
        if(array[i]==x)
        {
            cout<<"The value is found at the index : " <<i;

            break;
        }
        else
        {
           cout<<"The value is not found in the array"<<endl;
        break;
        }
    }


    return 0;
}

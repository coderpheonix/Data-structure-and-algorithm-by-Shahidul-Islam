#include<iostream>
using namespace std;

int i , array[5]={3,8,6,77,9}, n=5;

void InsertionSort ()
{
    for(i=1;i<n;i++)
    {
        int key=array[i];
        int j=i-i;

         while (j >= 0 && array[j] > key)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+i]=key;
    }
}


void print()
{
    for(i=0;i<n;i++)
    {
        cout<<array[i]<<endl;
    }
}



int main ()
{
    cout<<"Before sorted: "<<endl;
    print();
    InsertionSort();
    cout<<"After sorted: "<<endl;
    print();
    return 0;


}

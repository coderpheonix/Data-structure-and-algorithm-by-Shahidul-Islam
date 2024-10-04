#include<iostream>
#include<queue>

using namespace std;

int main ()
{
    priority_queue<int>pq;
    pq.push(10);
    pq.push(25);
    pq.push(26);

    if(pq.empty())
    {
        cout<<"The Queue is empty";
    }
    else
    {
        cout<< "The priority Queue is not empty"<<endl;
    }

    // the element is
    cout <<" the top element is : " <<pq.top()<< endl;

    // remove the top element

    pq.pop(); // removed the to elements

     //
      cout <<" the top element is : " <<pq.top()<< endl;

      // Added some more value
      pq.push(88);
      pq.push(56);

      cout<<"After pushed element the max is:" << pq.top()<< endl;

      // Size of the elements

      cout<<" The size of the given element is : " << pq.size()<<endl;

      while (!pq.empty())
      {
          pq.top();
          pq.pop();
      }


     if(pq.empty())
       {
      cout<<"The priority queue is now empty after removals!"<<endl;
       }









    return 0;

}

#include <iostream>
#include "QueueLinkedList"
using namespace std;

int main()
{
    //test QueueLinkedLIst
    QueueLinkedList myQueue;
    if(myQueue.isEmpty())
       cout<<"The Queue is empty"<<endl;
    else
       cout << "The Queue is not empty"<<endl;

    for ( int i = 0 ; i < 3; i++)
    {   
    int item;
    cout<<"enter item to enqueue in the Queue"<<endl;
    cin>> item;
    myQueue.enqueue(item);
    cout << "--- Current Queue Content ---" << endl; 
    myQueue.display();
    }

    



    
}
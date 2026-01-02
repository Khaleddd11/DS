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

    //test dequeue 
    myQueue.dequeue();
    cout << "--- Current Queue Content after one dequeue ---" << endl;
    myQueue.display();

    //test getFront
    cout << "Front item is: " << myQueue.getFront() << endl;

    //test isFound 
    int item;
    cout<<"enter item to search for in the Queue"<<endl;
    cin>>item;
    if(myQueue.isFound(item)){
        cout <<"item found in the Queue"<<endl;
        }
        else{
            cout <<"item not found in the Queue"<<endl;}
    
    //test clearALlItems
    cout<<"Clearing all items from the Queue..."<<endl;
    myQueue.clearAllItems();
    if(myQueue.isEmpty())
       cout<<"The Queue is empty"<<endl;
    else
       cout << "The Queue is not empty"<<endl;
    



    
}
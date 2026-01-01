#include <iostream>
#include "LinkedList.h"
using namespace std;


int main(){
    LinkedList myList;
    if(myList.isEmpty())
       cout<<"The list is empty"<<endl;
    else
       cout << "The List has" << myList.count()<<endl;
    
    int item;
    cout<<"enter item to insert in the list"<<endl;
    cin>> item;
    myList.insertFirst(item);
    myList.display();

    cout<<"enter item to insert in the list"<<endl;
    cin>> item;
    myList.insertFirst(item);
    myList.display();

    cout<<"enter item to insert in the list"<<endl;
    cin>> item;
    myList.insertFirst(item);
    myList.display();

    cout << "The List has" << myList.count()<<endl;

    cout<<"enter item to search for in the list"<<endl;
    cin>>item;
    if(myList.isFound(item)){
      cout <<"item found in the list"<<endl;
    }
    else{
        cout <<"item not found in the list"<<endl;}


}
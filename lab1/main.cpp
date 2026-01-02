#include <iostream>
#include "LinkedList.h"
using namespace std;


int main(){
    LinkedList myList;
    if(myList.isEmpty())
       cout<<"The list is empty"<<endl;
    else
       cout << "The List has" << myList.getcount()<<endl;
    
    int item;
    cout<<"enter item to insert in the list"<<endl;
    cin>> item;
    myList.insertFirst(item);
    cout << "--- Current List Content ---" << endl; // Add this label!
    myList.display();
    cout << "----------------------------" << endl;

    cout<<"enter item to insert in the list"<<endl;
    cin>> item;
    myList.insertFirst(item);
    cout << "--- Current List Content ---" << endl; // Add this label!
    myList.display();
    cout << "----------------------------" << endl;

    cout<<"enter item to insert in the list"<<endl;
    cin>> item;
    myList.insertFirst(item);
    cout << "--- Current List Content ---" << endl; // Add this label!
    myList.display();
    cout << "----------------------------" << endl;

    cout << "The List has " << myList.getcount()<< " items"<<endl;

    cout<<"enter item to search for in the list"<<endl;
    cin>>item;
    if(myList.isFound(item)){
      cout <<"item found in the list"<<endl;
    }
    else{
        cout <<"item not found in the list"<<endl;}
    

    int newValue;    
    cout<<"enter  new item that you want to add and an item already in the list to insert before it"<<endl;
    cout << "New Value: ";
    cin>>newValue;
    cout << "Before Value: ";
    cin>>item;
    myList.insertBefore(newValue,item);
    cout << "--- Current List Content ---" << endl; 
    myList.display();

    cout << "enter new item that you want to add and an item already in the list to insert after it"<< endl;
    cout << "New Value: ";
    cin>>newValue;
    cout << "After Value: ";
    cin>>item;
    myList.After(newValue,item);
    cout << "--- Current List Content ---" << endl;
    myList.display();

    /*test the getDataByIndex function*/
    int index;
    cout << "Enter index to get data at that index: ";
    cin >> index;
    cout << "Data at index " << index << " is: " << myList.getDataByIndex(index);
    

    // append
    cout << "\nEnter item to append to the list: ";
    cin >> item;
    myList.append(item);
    cout << "--- Current List Content ---" << endl;
    myList.display();

}
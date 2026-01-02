#include <iostream>
#include "Node.h"
using namespace std;
class LinkedList{
    public: 
    Node* head;

    LinkedList()
    {
        head = nullptr;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    void insertFirst(int newValue ){
        Node* newNode = new Node();
        newNode ->data = newValue;

        if (isEmpty()){
            newNode ->next = nullptr;
            head=newNode;
        }
        else{
            newNode ->next=head;
            head=newNode;
        }
    }

    void display()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout<< temp->data<<" ";
            temp=temp->next;
        }
    }

    int getcount()
    {
        int getcount =0;
        Node* temp = head;
        while(temp != nullptr)
        {
            getcount++;
            temp=temp->next;
        }
        return getcount;
    }

    bool isFound( int key)
    {
        bool found = false;
        Node* temp = head;
        while(temp != nullptr)
        {
            if(temp->data == key){
                found = true;
            }
            temp= temp->next;
        }
        return found;
    }

    void insertBefore(int data, int beforeData)
    {
        if(isEmpty())
        {
            insertFirst(data);
        }
        if(isFound(beforeData))
        {
        Node* newNode = new Node();
        newNode ->data =data;

        Node* temp= head;
        while(temp  != nullptr && temp->next->data != beforeData)
        {
            temp = temp ->next;
        }
        newNode->next=temp->next;
        temp->next = newNode;
    }
    else
    {
        cout<<"Item not found"<<endl;
    }
    }

    void After(int data, int afterData)
    {
        if(isEmpty())
        {
            insertFirst(data);
        }
        if(isFound(afterData))
        {
        Node* newNode = new Node();
        newNode ->data =data;

        Node* temp= head;
        while(temp  != nullptr && temp->data != afterData)
        {
            temp = temp ->next;
        }
        newNode->next=temp->next;
        temp->next = newNode;
    }
    else
    {
        cout<<"Item not found"<<endl;
    }
    }

    int getDataByIndex(int index)
    {
        int counter = 0 ;
        Node* temp = head;
        while( temp != nullptr && counter !=index)
        {
            temp = temp->next;
            counter ++;
        }
        if(temp != nullptr) {
            return temp->data;
        } 
        else {
            cout << "Error: Index out of range" << endl;
            return -1; 
        }
    }
};
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

    void append( int newValue)
    {
        if(isEmpty())
        {
            insertFirst(newValue);
        }
        else 
        {
        Node* temp= head;
        while(temp->next !=nullptr)
        {
            temp = temp->next;
        }
        Node* newNode= new Node();
        newNode->data= newValue;

        temp->next=newNode;
        newNode->next=nullptr;
        }

    }

    void remove(int data)
    {
        if(isEmpty())
        {
            cout<<"List is already empty, no items to delete"<<endl;
        }

        if(head->data == data )
        {
            Node* delPtr=head;
            head=head->next;
            delete delPtr;
        } 

        else
        {
        Node* delPtr= head;
        Node* prev= nullptr;

        while(delPtr != nullptr && delPtr->data != data){
            prev= delPtr;
            delPtr=delPtr->next;
        }
        prev->next =delPtr->next;
        delete delPtr;
        }

    }

        void removeAll(int data)
        {
            if(isEmpty())
            {
                cout<<"List is already empty, no items to delete"<<endl;
            }

            //head
            while (head != nullptr && head->data == data) {
            Node* delPtr = head;
            head = head->next;
            delete delPtr;
        }

            Node* temp= head;
            while(temp!= nullptr && temp->next != nullptr)
            {
                if (temp->next->data == data)
                {
                    Node* delptr = temp->next;
                    temp->next = delptr->next;
                    delete delptr;
                }
                else
                {
                    temp= temp->next;
                }

            }
        
        }
        

        void secondRemoveAll(int data)
{
    // Repeat the removal as long as the item exists in the list
    while (isFound(data)) 
    {
        remove(data);
    }
}
};
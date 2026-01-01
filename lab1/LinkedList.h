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
        Node* newNode;
        newNode ->data =newValue;

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
            cout<< temp->data<<endl;
            temp=temp->next;
        }
    }

    int count()
    {
        int count;
        Node* temp = head;
        while(temp != nullptr)
        {
            count++;
            temp=temp->next;
        }
        return count;
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
};
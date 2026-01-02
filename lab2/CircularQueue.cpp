#include <iostream>
using namespace std;

/*
Simple Queue :
  problems : deleted Elements cant Be reused
  solution : Circular Queue

Delete ===> Front
Insert ===> Rear
==================================================
Circular Queue
Delete ===> Front
Insert ===> Rear
==================================================
Priority Queue

Delete ===> Priority, Front
Insert ===>  Rear
==================================================
Double Ended Queue
=============================
Input Restricted  [One Inertion , Both Delete]
insertRear();
deleteFront();
deleteRear();


Output Restricted
insertRear();
insertFront();
deleteFront();


*/
class MinaQueue{
    private :
        int * items ;
        int rear ; //EnterIndex
        //int front; //OutIndex
        int capicty;
        int size;
    public:
    int front; //OutIndex
    MinaQueue(int capicty){
        rear=-1;
        front=-1;
        //size=0;
        this->capicty=capicty;
        items=new int[capicty];
    }
    ~MinaQueue(){
        delete [] items;
    }
    void insertRear(int item){
        //Check Full
        if((front == 0 && rear == capicty-1 ) || (front == rear +1 )){
          //if(size == capicty){}
            //Resize Dynamic Array
            cout<<"is Full "<<endl;
            return ;
        }

        //Setting Rear and Front
        //First Element
        if(rear == -1 &&  front == -1  ){
            rear=0;
            front=0;
        }else if (rear == capicty-1){ //&& front != 0
            rear=0;
        }else{
            rear++;
        }
        //Add item
        items[rear]=item;
        //size++;

    }
    int deleteFront(){
        //Check Empty
        if(front == -1 ){cout<<"Empty Queue" ; return -1;}
        //if(size == 0 ){cout<<"Empty Queue" ; return -1;}

        //Backup Item
        int temp = items[front];
        //Delete Item
        items[front]=-10;//-10 for Debug
        //Change Front and Rear
        if(front == rear ){
         front =-1;
         rear=-1;
        }else if (front == capicty -1 ){
            front =0;
        }
        else{
            front ++;
        }
        //return Item
        //size--;
        return temp;
    }

    void display(){
    cout<<"\n========================================\n";

        //Empty
        if(front == -1 ){cout<<"Empty Queue" ; return ;}
        /*if(front <= rear){
            for (int i= front ; i<= rear; i++){
                cout<<items[i]<< "\t";
            }
        }else { //front >= rear
            for (int i= front ; i< capicty; i++){
                cout<<items[i]<< "\t";
            }
            for (int i= 0 ; i<= rear; i++){
                cout<<items[i]<< "\t";
            }

        }*/
        //rear =0 front =1
        //front 3   rear = 2   3 4 0 1 2
        int i = (front)%capicty; // 3%5 ===> 3
        while(i != rear){
            cout<<items[i]<< "\t";
            i=(i+1)%capicty;
        }
        cout<<items[rear];
        cout<<"\n========================================\n";
    }



    void insertFront(int item){
        if((front == 0 && rear == capicty-1 ) || (front == rear +1 ))
        {
            cout<<"is Full "<<endl;
            return ;
        }
        // Check Empty
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }

        // If front is at the start (0), we wrap it to the very end of the array
        else if(front == 0){
            front = capicty - 1;
        }
        // Normal Case
        else{
            front--;
        }
        //  Add the item
        items[front] = item;


    }
    void deleteRear(){
        if(front == -1){
            cout<<"Empty Queue"; 
            return;
    }

    // Only one element left
        if(front == rear){
            front = -1;
            rear = -1;
        }

        // If rear is at 0, we wrap around 
        else if(rear == 0){
            rear = capicty - 1;
        }
        // Normal case
        else{
            rear--;
        }
    }
};






int main()
{
     MinaQueue q(5);
     cout << "--- Inserting Front ---" << endl;
     q.insertFront(10);
     q.insertFront(20);
     q.insertFront(30);
     q.insertFront(40);
     q.insertFront(50);
     q.insertFront(60);
     q.display();//10 20 30 40 50

     cout << "--- Deleting Rear ---" << endl;
     q.deleteRear(); 
     q.deleteRear(); 
     
     q.display();


     q.insertFront(70); //rear = 0
     q.insertFront(80); //rear = 1
     q.display();//30 40 50 70 80


    cout << "--- Deleting All ---" << endl;
     q.deleteRear();
     q.deleteRear();
     q.deleteRear();
     q.deleteRear();
     q.deleteRear();
     q.deleteRear(); // Should be empty now
     
     q.display(); // Empty

     q.insertFront(90);
     q.insertFront(100);
     q.insertFront(1000);
     q.display();//90 100 1000
    cout << "Hello world!" << endl;

    //insertFront
    q.insertFront(5);




    return 0;
}
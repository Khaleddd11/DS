#include <iostream>
#include "../../lab1/LinkedList.h"
using namespace std;


class SortingLinkedList :public LinkedList{
    public:

    void BubbleSort()
    {
        if(isEmpty()) return;

        int count = getcount();
        // Outer loop 
        for(int i = 0; i < count - 1; i++)
        {
            Node* temp = head;
            // Inner loop goes until the end minus sorted part
            for(int j = 0; j < count - i - 1; j++)
            {
                // Compare current node with next node
                if(temp->data > temp->next->data)
                {
                    // Swap Data
                    int swapVar = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = swapVar;
                }
                temp = temp->next;
            }
        }
    }


    void SelectionSort()
    {
        Node* temp = head;

        while(temp != nullptr)
        {
            Node* minNode = temp;
            Node* scanner = temp->next;

            // get the minimum in the remaining list
            while(scanner != nullptr)
            {
                if(scanner->data < minNode->data)
                {
                    minNode = scanner;
                }
                scanner = scanner->next;
            }

            // Swap data between current temp and the found minNode
            int swapVar = temp->data;
            temp->data = minNode->data;
            minNode->data = swapVar;

            temp = temp->next;
        }
    }

    void InsertionSort()
{
    Node* sortedHead = nullptr; 
    Node* current = head;       

    // Loop through every node in the original list
    while (current != nullptr)
    {
        // 2. Save the Next Node
        Node* nextNode = current->next; 

        // 3. case a, Insert at the very front (Head)
        // If the sorted list is empty OR the item is smaller than the first item.
        if (sortedHead == nullptr || sortedHead->data >= current->data)
        {
            current->next = sortedHead; 
            sortedHead = current;     
        }
        
        // 4. case b, Insert in the middle or end
        else
        {
            // temporary pointer to scan through the sorted list
            Node* temp = sortedHead;
            
            // Walk as long as the next number is smaller than my current number
            // We stop right before the spot where we want to insert.
            while (temp->next != nullptr && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            
            // 1. Connect current to the neighbor on the right
            current->next = temp->next;
            // 2. Connect the neighbor on the left (temp) to current
            temp->next = current;
        }

        // 5. Move to the next item in the original list
        current = nextNode; 
    }
    // The old 'head' is garbage now
    head = sortedHead; 
}

int LinearSearch(int key)
    {
        int index = 0;
        Node* temp = head;
        while(temp != nullptr)
        {
            if(temp->data == key){
                return index; // Found
            }
            temp = temp->next;
            index++;
        }
        return -1; // Not Found
    }


    // 5. Binary Search
    // Helper to find middle node between start and end
    Node* getMiddle(Node* start, Node* last)
    {
        if (start == nullptr) return nullptr;

        Node* slow = start;
        Node* fast = start->next;

        while (fast != last)
        {
            fast = fast->next;
            // Only move Slow if Fast hasn't hit the end 
            if (fast != last)
            {   
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

    // Main Binary Search Function
    bool BinarySearch(int key)
    {
        Node* start = head;
        Node* last = nullptr;

        while (last == nullptr || last != start)
        {
            // Find Middle
            Node* mid = getMiddle(start, last);
            
            if (mid == nullptr) return false;

            if (mid->data == key)
                return true; // Found

            else if (mid->data < key)
                start = mid->next; // Search Right Half
            
            else
                last = mid; // Search Left Half
        }
        return false; // Not Found
    }
};
    


int main()
{
    // 
    // linear search & bubble Sort
    cout << "\n--- TEST 1: Linear Search & Bubble Sort ---\n";
    SortingLinkedList list1;
    list1.insertFirst(10);
    list1.insertFirst(40);
    list1.insertFirst(20);
    list1.insertFirst(50);
    list1.insertFirst(30);

    cout << "Original List: ";
    list1.display(); // 30 50 20 40 10

    // Test Linear Search
    int key = 20;
    int index = list1.LinearSearch(key);
    if(index != -1)
        cout << "Linear Search: Found " << key << " at index " << index << endl;
    else
        cout << "Linear Search: " << key << " not found." << endl;

    // Test Bubble Sort
    cout << "Running Bubble Sort..." << endl;
    list1.BubbleSort();
    cout << "Sorted List:   ";
    list1.display(); //10 20 30 40 50


    // Selection Sort
    cout << "\n--- TEST 2: Selection Sort ---\n";
    SortingLinkedList list2;
    list2.insertFirst(5);
    list2.insertFirst(1);
    list2.insertFirst(100);
    list2.insertFirst(3);

    cout << "Original List: ";
    list2.display(); // 3 100 1 5

    cout << "Running Selection Sort..." << endl;
    list2.SelectionSort();
    cout << "Sorted List:   ";
    list2.display(); // 1 3 5 100



    // Insertion sort & binary Search

    cout << "\n--- TEST 3: Insertion Sort & Binary Search ---\n";
    SortingLinkedList list3;
    list3.insertFirst(88);
    list3.insertFirst(11);
    list3.insertFirst(44);
    list3.insertFirst(99);
    list3.insertFirst(22);

    cout << "Original List: ";
    list3.display(); 

    cout << "Running Insertion Sort..." << endl;
    list3.InsertionSort();
    cout << "Sorted List:   ";
    list3.display(); //11 22 44 88 99

    // Test Binary Search 
    int searchVal1 = 44;
    int searchVal2 = 1000;

    // Search for existing value
    if(list3.BinarySearch(searchVal1))
        cout << "Binary Search: Value " << searchVal1 << " found!" << endl;
    else
        cout << "Binary Search: Value " << searchVal1 << " NOT found." << endl;

    // Search for non-existing value
    if(list3.BinarySearch(searchVal2))
        cout << "Binary Search: Value " << searchVal2 << " found!" << endl;
    else
        cout << "Binary Search: Value " << searchVal2 << " NOT found." << endl;

    return 0;
}
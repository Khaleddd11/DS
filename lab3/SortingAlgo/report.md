Bubble Sort: Can be implemented on a linked list. It uses nested loops to compare and swap data. While valid, the O(n2) complexity makes it very slow for large lists, and swapping data repeatedly is unnecessary overhead. 

Selection Sort: Can be implemented by finding the minimum node in the unsorted part and swapping data. Like Bubble Sort, it has O(n2) complexity. It performs fewer swaps than Bubble Sort but is still inefficient for traversing linked structures. 

Insertion Sort: This is the most efficient of the O(n2) sorting algorithms for Linked Lists. Unlike arrays, inserting a node does not require shifting all other elements (which is expensive); it only requires changing two pointers. 

Linear Search: The standard way to search a Linked List. Since linked lists do not have index numbers (like arr[5]), we must visit every node sequentially. It works on both sorted and unsorted data. 

Binary Search: Theoretically possible (as we implemented), but bad for Linked Lists. Binary Search relies on jumping instantly to the middle. In a Linked List, "jumping" to the middle requires traversing nodes one by one (O(n/2)). This overhead means the algorithm takes O(n) total time, defeating the O(logn) speed advantage of Binary Search. 

Here is my ranking for them :

Sorting Algorithms

    Insertion Sort (Best for Linked Lists)

    Selection Sort (Fewer swaps than Bubble)

    Bubble Sort (Too many swaps)

Searching Algorithms

    Linear Search (Best approach)

    Binary Search (Too much overhead to find the middle)
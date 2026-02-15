Question 6 Documentation

(a) DATA STRUCTURES

• Array is used to represent heap
• For any element at index i:
• Left child = 2*i + 1
• Right child = 2*i + 2
• In Min Heap → Parent node is smaller than children
• In Max Heap → Parent node is larger than children

(b) FUNCTIONS IMPLEMENTED

• swap() – Swaps two elements
• minHeapify() – Maintains min heap property
• buildMinHeap() – Converts array into Min Heap
• maxHeapify() – Maintains max heap property
• buildMaxHeap() – Converts array into Max Heap
• display() – Prints the heap

(c) MAIN METHOD ORGANIZATION

• Define an unsorted array:
20, 15, 30, 5, 10, 25, 40

• Display original array
• Build Min Heap
• Display Min Heap
• Build Max Heap
• Display Max Heap
• End program

(d) SAMPLE OUTPUT

BUILD MIN HEAP AND MAX HEAP

Original Array:
20 15 30 5 10 25 40

Min Heap:
5 10 25 20 15 30 40

Max Heap:
40 15 30 5 10 25 20

Explanation

• Heap is a complete binary tree represented using an array.
• Min Heap ensures smallest element is at root.
• Max Heap ensures largest element is at root.
• Heapify process rearranges elements to maintain heap property.
• Both heaps are built from the same unsorted data.
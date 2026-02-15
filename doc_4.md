Question 4 Documentation:
 
(a) DATA STRUCTURES
Doubly Linked List Node Structure:

• Has data to store integer value
• Has prev pointer to previous node
• Has next pointer to next node
• NULL indicates start or end of list

(b) FUNCTIONS IMPLEMENTED
Basic Functions:

• createNode() - Creates a new node with given data
• insertAtEnd() - Inserts node at end (used for demonstration)
• display() - Prints list from start to end

Doubly Linked List Operations:

• insertAfter() - Inserts a new node after a given node
• Adjusts next pointer of previous node
• Adjusts prev pointer of new node
• Updates surrounding links properly

• deleteNode() - Deletes a given node
• Updates previous node’s next pointer
• Updates next node’s prev pointer
• Frees memory of deleted node

(c) MAIN METHOD ORGANIZATION

• Create empty list (head = NULL)

• Insert nodes:
• 10
• 20
• 30
• 40

• Display list
• Insert 25 after node 20
• Display updated list
• Delete node 30
• Display final list
• End program

(d) SAMPLE OUTPUT

DOUBLY LINKED LIST IMPLEMENTATION

• List: 10 <-> 20 <-> 30 <-> 40 <-> NULL
• After inserting 25 after 20:
10 <-> 20 <-> 25 <-> 30 <-> 40 <-> NULL
• After deleting 30:
10 <-> 20 <-> 25 <-> 40 <-> NULL


Explanation:

• Doubly linked list allows traversal in both directions
• Insertion after a given node requires updating four pointers
• Deletion requires adjusting surrounding nodes
• Memory is dynamically allocated and freed properly
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end of linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    // If list is empty, make new node as head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the last node
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Insert new node at end
    temp->next = newNode;
}

// Function to display linked list in forward direction
void displayForward(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse traverse and display linked list (using recursion)
void reverseTraversal(Node* head, int isFirst) {
    // Base case: if list is empty or reached end
    if (head == NULL) {
        return;
    }
    
    // Recursive call to reach the end
    reverseTraversal(head->next, 0);
    
    // Print while returning from recursion
    printf("%d", head->data);
    if (!isFirst) {
        printf(" <- ");
    }
}

// Wrapper function to display reverse traversal
void displayReverse(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Reverse: ");
    reverseTraversal(head, 1);
    printf("\n");
}

// Function to count nodes in linked list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to free the linked list
void freeList(Node** head) {
    Node* current = *head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
}

int main() {
    printf("LINKED LIST REVERSE TRAVERSAL\n");
    printf("==============================\n\n");
    
    Node* head = NULL;
    
    // Test 1: Create a linked list with 5 nodes
    printf("Test 1: Creating linked list with values 10, 20, 30, 40, 50\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("Number of nodes: %d\n", countNodes(head));
    displayForward(head);
    displayReverse(head);
    printf("-------------------------------\n\n");
    
    // Test 2: Add more elements
    printf("Test 2: Adding elements 60, 70, 80\n");
    insertAtEnd(&head, 60);
    insertAtEnd(&head, 70);
    insertAtEnd(&head, 80);
    
    printf("Number of nodes: %d\n", countNodes(head));
    displayForward(head);
    displayReverse(head);
    printf("-------------------------------\n\n");
    
    // Test 3: Single element list
    printf("Test 3: Creating new list with single element 100\n");
    Node* head2 = NULL;
    insertAtEnd(&head2, 100);
    
    printf("Number of nodes: %d\n", countNodes(head2));
    displayForward(head2);
    displayReverse(head2);
    printf("-------------------------------\n\n");
    
    // Test 4: Two elements
    printf("Test 4: Adding element 200 to single element list\n");
    insertAtEnd(&head2, 200);
    
    printf("Number of nodes: %d\n", countNodes(head2));
    displayForward(head2);
    displayReverse(head2);
    printf("-------------------------------\n\n");
    
    // Free memory
    freeList(&head);
    freeList(&head2);
    
    printf("Memory freed successfully!\n");
    printf("==============================\n");
    
    return 0;
}

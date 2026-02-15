Question 5 Documentation

(a) Data Structures

• Adjacency matrix (2D array) to represent graph
• 1 means edge exists
• 0 means no connection
• Visited array to track visited vertices

(b) Functions Implemented

• addEdge() – Adds edge between two vertices
• displayMatrix() – Displays adjacency matrix
• BFS() – Uses queue to traverse graph level by level
• DFS() – Uses recursion to traverse graph deeply

(c) Main Method Organization
• Set number of vertices = 6

• Add edges:
• 0 – 1
• 0 – 3
• 1 – 2
• 2 – 4
• 3 – 5
 
• Display adjacency matrix
• Perform BFS from vertex 0
• Perform DFS from vertex 0

(d) Sample Output

Adjacency Matrix:

0 1 0 1 0 0
1 0 1 0 0 0
0 1 0 0 1 0
1 0 0 0 0 1
0 0 1 0 0 0
0 0 0 1 0 0

BFS Traversal:
0 1 3 2 5 4

DFS Traversal:
0 1 2 4 3 5

Explanation

• The graph is represented using a matrix.
• BFS explores nodes level by level using queue.
• DFS explores as deep as possible using recursion.
• Different traversal methods produce different visiting orders.
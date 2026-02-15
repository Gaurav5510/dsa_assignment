Question 7 Documentation

(a) Data Structures

• A 2D array (adjacency matrix) is used to represent the weighted graph
• Each cell contains the weight of the edge
• If there is no edge, value is 0
• distance[] array stores shortest distances
• visited[] array keeps track of processed nodes

(b) Functions Implemented

• findMinVertex()
• Selects the unvisited node with the smallest distance

• dijkstra()
• Initializes distance values
• Repeatedly selects minimum distance node
• Updates neighboring node distances
• Prints final shortest paths

(c) Main Method Organization

• Define number of vertices = 5
• Initialize graph matrix

• Add edges manually:
• 0 → 1 (6)
• 0 → 2 (3)
• 1 → 2 (2)
• 1 → 3 (5)
• 2 → 1 (1)
• 2 → 3 (8)
• 2 → 4 (7)
• 3 → 4 (4)
• 4 → 3 (2)

• Set source node = 0
• Call Dijkstra function
• Print shortest distances

(d) Sample Output

DIJKSTRA'S SHORTEST PATH ALGORITHM

Shortest distances from source node 0:
Node 0 -> 0
Node 1 -> 4
Node 2 -> 3
Node 3 -> 9
Node 4 -> 10

Explanation
• The algorithm starts from source node 0
• It always selects the closest unvisited node
• Distances are updated when a shorter path is found
• Final output shows shortest distance from source to all other nodes
• Works only for graphs with non-negative weights
#include <stdio.h>

#define MAX 10
#define INF 9999

int n = 5;

int findMinVertex(int distance[], int visited[]) {
    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int source) {

    int distance[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[source] = 0;

    for (int count = 0; count < n - 1; count++) {

        int u = findMinVertex(distance, visited);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from source node %d:\n\n", source);

    for (int i = 0; i < n; i++) {
        printf("Node %d -> %d\n", i, distance[i]);
    }
}

int main() {

    int graph[MAX][MAX] = {0};

    printf("DIJKSTRA'S SHORTEST PATH ALGORITHM\n\n");
    
    graph[0][1] = 6;
    graph[0][2] = 3;
    graph[1][2] = 2;
    graph[1][3] = 5;
    graph[2][1] = 1;
    graph[2][3] = 8;
    graph[2][4] = 7;
    graph[3][4] = 4;
    graph[4][3] = 2;

    int source = 0;

    dijkstra(graph, source);

    return 0;
}

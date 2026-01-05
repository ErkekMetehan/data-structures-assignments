#include <stdio.h>
#include <stdlib.h>

#define V 5

int queue[V], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == V - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void DFS(int graph[V][V], int visited[], int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

void BFS(int graph[V][V], int start) {
    int visited[V] = {0};
    
    enqueue(start);
    visited[start] = 1;

    printf("BFS Siralamasi: ");
    while (front <= rear && front != -1) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < V; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    int visitedDFS[V] = {0};
    printf("DFS Siralamasi: ");
    DFS(graph, visitedDFS, 0);
    printf("\n");


    front = -1; rear = -1;
    BFS(graph, 0);

    return 0;
}

#include <stdio.h>

#define V 6


void DFS(int graph[V][V], int ziyaretEdildi[V], int v) {
    ziyaretEdildi[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {

        if (graph[v][i] == 1 && !ziyaretEdildi[i]) {
            DFS(graph, ziyaretEdildi, i);
        }
    }
}

void clusterBul(int graph[V][V]) {
    int ziyaretEdildi[V] = {0};
    int clusterSayisi = 0;

    printf("Graph icindeki Kumeler (Clusters):\n");
    for (int i = 0; i < V; i++) {
        if (!ziyaretEdildi[i]) {
            clusterSayisi++;
            printf("Cluster %d: { ", clusterSayisi);
            DFS(graph, ziyaretEdildi, i);
            printf("}\n");
        }
    }
}

int main() {

    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    clusterBul(graph);

    return 0;
}g

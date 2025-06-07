#include <iostream>
#include <queue>
using namespace std;

const int MAX_V = 20;
const int MAX_EDGES = 10;
// This code implements a Best-First Search algorithm using a priority queue.

struct Edge {
    int to;
    int cost;
};

Edge adj[MAX_V][MAX_EDGES];
int adjSize[MAX_V] = {0};
// Function to add an edge to the adjacency list

void addEdge(int u, int v, int cost) {
    adj[u][adjSize[u]].to = v;
    adj[u][adjSize[u]].cost = cost;
    adjSize[u]++;

    adj[v][adjSize[v]].to = u;
    adj[v][adjSize[v]].cost = cost;
    adjSize[v]++;
}


void bestFirstSearch(int src, int target) {
    bool visited[MAX_V] = {false};
    priority_queue< pair<int, int>, queue<pair<int, int>>::container_type, greater<pair<int, int>> > pq;

    int path[MAX_V];
    int pathLen = 0;

    pq.push(make_pair(0, src));
    visited[src] = true;

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        path[pathLen++] = node;

        if (node == target) break;

        for (int i = 0; i < adjSize[node]; i++) {
            int next = adj[node][i].to;
            int cost = adj[node][i].cost;
            if (!visited[next]) {
                visited[next] = true;
                pq.push(make_pair(cost, next));
            }
        }
    }

    for (int i = 0; i < pathLen; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main() {
    int V = 14;

    
    int edges[][3] = {
        {0, 1, 3}, {0, 2, 6}, {0, 3, 5}, {1, 4, 9}, {1, 5, 8},
        {2, 6, 12}, {2, 7, 14}, {3, 8, 7}, {8, 9, 5}, {8, 10, 6},
        {9, 11, 1}, {9, 12, 10}, {9, 13, 2}
    };

    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int cost = edges[i][2];
        addEdge(u, v, cost);
    }

    int source = 0, target = 9;
    bestFirstSearch(source, target);

    return 0;
}
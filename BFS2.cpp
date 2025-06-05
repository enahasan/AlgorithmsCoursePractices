#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    
    void bfsOfGraph(int V, int adj[][100], int adjSize[], int bfs[], int &bfsIndex) {
        int vis[1000] = {0};  
        vis[0] = 1;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            bfs[bfsIndex++] = node;

            for (int i = 0; i < adjSize[node]; ++i) {
                int neighbor = adj[node][i];
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int V = 5; 

    int adj[100][100];     
    int adjSize[100] = {0}; 

    
    adj[0][adjSize[0]++] = 1;
    adj[0][adjSize[0]++] = 2;
    adj[1][adjSize[1]++] = 0;
    adj[1][adjSize[1]++] = 3;
    adj[2][adjSize[2]++] = 0;
    adj[2][adjSize[2]++] = 4;
    adj[3][adjSize[3]++] = 1;
    adj[4][adjSize[4]++] = 2;

    int bfs[100];   
    int bfsIndex = 0;

    Solution obj;
    obj.bfsOfGraph(V, adj, adjSize, bfs, bfsIndex);

    cout << "BFS Traversal: ";
    for (int i = 0; i < bfsIndex; ++i) {
        cout << bfs[i] << " ";
    }
    cout << endl;

    return 0;
}
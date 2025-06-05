#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[1000] = {0};  // Assuming V <= 1000
        vis[0] = 1;

        queue<int> q;
        q.push(0);

        vector<int> bfs;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        return bfs;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V];

    // Creating an undirected graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);

    Solution obj;
    vector<int> result = obj.bfsOfGraph(V, adj);

    cout << "BFS Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
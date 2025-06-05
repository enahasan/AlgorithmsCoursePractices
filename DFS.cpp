#include <iostream>
#include <vector>

using namespace std;

void dfsRec(const vector<vector<int> >& adj, vector<bool>& visited, int s, vector<int>& res) {
    visited[s] = true;
    res.push_back(s);
    for (int i : adj[s]) {
        if (!visited[i]) {
            dfsRec(adj, visited, i, res);
        }
    }
}

vector<int> DFS(const vector<vector<int> >& adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsRec(adj, visited, 0, res);
    return res;
}

void addEdge(vector<vector<int> >& adj, int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main() {
    int V = 5;
    vector<vector<int> > adj(V);

    // Initialize edges without list initialization
    vector<vector<int> > edges;

    vector<int> e1; e1.push_back(1); e1.push_back(2); edges.push_back(e1);
    vector<int> e2; e2.push_back(1); e2.push_back(0); edges.push_back(e2);
    vector<int> e3; e3.push_back(2); e3.push_back(0); edges.push_back(e3);
    vector<int> e4; e4.push_back(2); e4.push_back(3); edges.push_back(e4);
    vector<int> e5; e5.push_back(2); e5.push_back(4); edges.push_back(e5);

    for (size_t i = 0; i < edges.size(); i++) {
        addEdge(adj, edges[i][0], edges[i][1]);
    }

    vector<int> res = DFS(adj);

    for (int vertex : res) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
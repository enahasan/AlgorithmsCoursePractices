#include <iostream>
using namespace std;

// This code implements the Depth First Search (DFS) algorithm for a graph represented as an adjacency list
const int MAX_V = 100;                  
const int MAX_EDGES_PER_NODE = 10;      


int adj[MAX_V][MAX_EDGES_PER_NODE];     
int adjSize[MAX_V];                     


bool visited[MAX_V];                    
int res[MAX_V];                         
int resSize = 0;                        


void addEdge(int s, int t) {
    adj[s][adjSize[s]++] = t;           
    adj[t][adjSize[t]++] = s;           
}


void dfsRec(int s) {
    visited[s] = true;                  
    res[resSize++] = s;                 

    
    for (int i = 0; i < adjSize[s]; i++) {
        int next = adj[s][i];
        if (!visited[next]) { 
            dfsRec(next);               
        }
    }
}


void DFS(int start) {
    
    for (int i = 0; i < MAX_V; i++) {
        visited[i] = false;
    }

    resSize = 0;                        
    dfsRec(start);                      
}

int main() {
    int V = 5;                          

    
    addEdge(1, 2);
    addEdge(1, 0);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(2, 4);

    DFS(0);                             

    
    for (int i = 0; i < resSize; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
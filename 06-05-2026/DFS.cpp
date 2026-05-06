#include <iostream>
#include <vector>
#include <string>
using namespace std;

void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<string>& nodeNames) {

    visited[u] = true;
    cout << "Enter Node: " << nodeNames[u] << endl;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, adj, visited, nodeNames);
        }
    }
}

int main() {
    vector<string> nodeNames = { "A", "B", "C", "D" };
    int V = nodeNames.size();

    // A conected with B and C , B with D
    vector<vector<int>> adj(V);
    adj[0] = {1, 2}; // A -> B, C
    adj[1] = {0, 3}; // B -> A, D
    adj[2] = {0};    // C -> A
    adj[3] = {1};    // D -> B

    vector<bool> visited(V, false);

    cout << " DFS from " << nodeNames[0] << ":" << endl;
    DFS(0, adj, visited, nodeNames);

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

void bfs(int startNode, const vector<vector<int>>& adj, vector<int>& distances, ofstream& output) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    q.push(startNode);
    visited[startNode] = true;
    distances[startNode] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distances[neighbor] = distances[curr] + 1; // Distance
                q.push(neighbor);
            }
        }
    }

    output << "Shortest distances from source " << startNode << ":\n";
    for (int i = 0; i < adj.size(); i++) {
        output << "Distance to vertex " << i << ": " << (distances[i] == numeric_limits<int>::max() ? "INF" : to_string(distances[i])) << "\n";
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input) {
        cerr << "Invalid file";
        return -1;
    }

    int n, m; // n = number of vertices, m = number of edges
    input >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        input >> u >> v;
        adj[u].push_back(v); // directed graph
    }

    int startNode;
    input >> startNode; // Read the starting node for BFS

    vector<int> distances(n, numeric_limits<int>::max());
    bfs(startNode, adj, distances, output);

    input.close();
    output.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int vertices;
    unordered_map<int, vector<pair<int, int>>> adj;
    vector<vector<int>> edges;
    vector<pair<int, int>> mst_edges;  // To store the MST edges

    void addele() {
        ifstream fin("numbers.txt");
        if (!fin.is_open()) {
            cout << "Error: Unable to open file." << endl;
            return;
        }

        fin >> vertices; 
        int val;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                fin >> val; 
                if (val != 0) {
                    adj[i].push_back({j, val});
                    edges.push_back({i, j, val});
                }
            }
        }

        fin.close(); 
    }

    void print() {
        for (auto it : adj) {
            cout << it.first << " -> ";
            for (auto p : it.second) {
                cout << "(" << p.first << " " << p.second << ") ";
            }
            cout << endl;
        }
    }

    int prims() {
    priority_queue<pair<int, int>> pq;
    vector<int> visited(vertices, 0);
    vector<int> parent(vertices, -1);  
    pq.push({0, 0});  
    int sum = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[u] == 1) {
            continue;
        }

        visited[u] = 1;
        sum += w;

       
        if (parent[u] != -1) {
            mst_edges.push_back({parent[u], u});
        }

       
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;

            if (!visited[v]) {
                pq.push({weight, v});
                parent[v] = u;  
            }
        }
    }

    return sum;
}

    void print_mst_edges() {
        cout << "MST Edges:" << endl;
        for (auto edge : mst_edges) {
            cout << edge.first << " - " << edge.second << endl;
        }
    }
};

int main() {
    ofstream fout;
    cout << "Enter number of vertices: ";
    int x;
    cin >> x;
    vector<vector<int>> ad(x, vector<int>(x));
    fout.open("numbers.txt");
    if (!fout.is_open()) {
        cout << "Error: Unable to open file for writing." << endl;
        return 1;
    }
    fout << x << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cin >> ad[i][j]; 
            fout << ad[i][j];
            if (j < x - 1) {
                fout << " "; 
            }
        }
        fout << endl; 
    }

    fout.close(); 
    Graph g1;
    g1.addele();
  
    g1.print();
    int ans = g1.prims();
    cout << "Minimum cost of MST = " << ans << endl;
    
    g1.print_mst_edges();  

    return 0;
}

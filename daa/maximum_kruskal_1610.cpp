#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    public:
    vector<int> rank,parent;
    DisjointSet(int n) 
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for (int i = 0; i <=n; i++)
        {
            parent[i] = i;
        }
    }
        int find(int x)
        {
            if (parent[x] == x)
            {
                return x;
            }
            return parent[x]=find(parent[x]);
        }
        void unionSet(int u, int v)
        {
            int ult_u = find(u), ult_v = find(v);
            if (ult_u == ult_v)
                return;
            if (rank[ult_u] < rank[ult_v])
                {
                    parent[ult_u] = ult_v;
                }
            else if (rank[ult_u] > rank[ult_v])
                {
                    parent[ult_v] = ult_u;
                }
            else
                {
                    parent[ult_v] = ult_u;
                    rank[ult_u]++;
                }
        }
};
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

    int kruskal() {
    DisjointSet ds(vertices);
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b)  
    {
        return a[2] > b[2];
    });

    int mstWeight = 0;
    vector<vector<int>> mstEdges;

    for (auto& edge : edges) {
        if (ds.find(edge[0]) != ds.find(edge[1])) {
            ds.unionSet(edge[0], edge[1]);
            mstEdges.push_back(edge);
            mstWeight += edge[2];
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto& edge : mstEdges) {
        cout << edge[0] << " - " << edge[1] << " : " << edge[2] << endl;
    }

    return mstWeight;
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
    int ans = g1.kruskal();
    cout << "Minimum cost of MST = " << ans << endl;
    
   

    return 0;
}

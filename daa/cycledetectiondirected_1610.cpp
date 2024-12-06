#include <iostream>
#include <unordered_map>
#include<fstream>
#include <vector>
using namespace std;

class Graph {
public:
    int vertices;
    unordered_map<int, vector<int>> adj;
  
     
    void addele()
    {
        ifstream fin("numbers.txt");
        if (!fin.is_open())
        {
            cout << "Error: Unable to open file." << endl;
            return;
        }

        fin >> vertices; 
        int val;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                fin >> val; 
                if (val !=0)
                {
                    adj[i].push_back(j);
                }
            }
        }

        fin.close(); 
    }
    

    void print() {
        cout << "Adjacency List:\n";
        for (auto it : adj) {
            cout << it.first << " -> ";
            for (auto p : it.second) {
                cout << p << " ";
            }
            cout << endl;
        }
    }
};

// Helper function to detect cycles using DFS
bool hasCycleDFS(int vertex, unordered_map<int, vector<int>>& adjlist, vector<int>& visited, vector<int>& recStack) {
    visited[vertex] = 1;
    recStack[vertex] = 1;

    for (int neighbor : adjlist[vertex]) {
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, adjlist, visited, recStack)) {
                return true;
            }
        } else if (recStack[neighbor]) { // Cycle detected
            return true;
        }
    }

    recStack[vertex] = 0; // Remove the vertex from the recursion stack
    return false;
}

// Function to check for cycles in the directed graph
bool hasCycle(int V, unordered_map<int, vector<int>>& adjlist) {
    vector<int> visited(V, 0);
    vector<int> recStack(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, adjlist, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
     ofstream fout;
    cout << "Enter number of vertices: ";
    int x;
    cin >> x;
    vector<vector<int>> ad(x, vector<int>(x));
    fout.open("numbers.txt");
    if (!fout.is_open())
    {
        cout << "Error: Unable to open file for writing." << endl;
        return 1;
    }
    fout << x << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> ad[i][j]; 
            fout << ad[i][j];
            if (j < x - 1)
            {
                fout << " "; 
            }
        }
        fout << endl; 
    }

    fout.close(); 
    Graph g1;
    g1.addele();
  

    if (hasCycle(g1.vertices, g1.adj)) {
        cout << "Cycle detected in the directed graph.\n";
    } else {
        cout << "No cycle detected in the directed graph.\n";
    }

    return 0;
}

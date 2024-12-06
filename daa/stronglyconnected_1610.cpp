#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include<stack>
using namespace std;

class Graph
{
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
                if (val == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        fin.close(); 
    }
    void print()
    {
        for (auto it : adj)
        {
            cout << it.first << " -> ";
            for (auto p : it.second)
            {
                cout << p << " ";
            }
            cout << endl;
        }
    }
    Graph getTranspose()
    {
        Graph g;
        g.vertices = vertices;

        for (auto it : adj)
        {
            int u = it.first;
            for (auto v : it.second)
            {
                g.adj[v].push_back(u); 
            }
        }

        return g;
    }
    void dfs1(unordered_map<int, vector<int>> &adj, int v, vector<int> &visited, stack<int> &st)
{
    visited[v] = 1;
    for (int u : adj[v])
    {
        if (!visited[u])
        {
            dfs1(adj, u, visited, st);
        }
    }
    st.push(v); 
}
void dfs2(unordered_map<int, vector<int>> &adj, int v, vector<int> &visited)
{
    visited[v] = 1;
    cout << v << " "; // Print component member
    for (int u : adj[v])
    {
        if (!visited[u])
        {
            dfs2(adj, u, visited);
        }
    }
}
void findSCCs(Graph &g)
{
    stack<int> st;
    vector<int> visited(g.vertices, 0);
    for (int i = 0; i < g.vertices; i++)
    {
        if (!visited[i])
        {
            dfs1(g.adj, i, visited, st);
        }
    }
    Graph gt = g.getTranspose();

    visited.assign(g.vertices, 0); 
    while (!st.empty())
    {
        int v = st.top();
        st.pop();

        if (!visited[v])
        {
            cout << "SCC: ";
            dfs2(gt.adj, v, visited); 
            cout << endl;
        }
    }
}
};

int main()
{
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
  
    g1.print();
    
    g1.findSCCs(g1);
    return 0;
}
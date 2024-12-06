#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include<stack>
#include<climits>
using namespace std;

class Graph
{
  public:
    int vertices;
    unordered_map<int, vector<pair<int,int>>> adj;
    vector<vector<int>> edges;

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
                    adj[i].push_back({j,val});
                    edges.push_back({i,j,val});
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
                cout <<"(" <<p.first<< " "<<p.second<<" "<<")";
            }
            cout << endl;
        }
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
vector<int> belmanford( vector<vector<int>> &edges,int vertices,int source)
{
    vector<int> distance(vertices,INT_MAX);
    distance[source]=0;
    for(int i=1;i<vertices;i++)
    {
        for(int j=0;j<edges.size();j++)
        {
       int u=edges[j][0];
       int v=edges[j][1];
       int w=edges[j][2];
       if(distance[u] !=INT_MAX &&distance[u]+w<distance[v])
       {
        distance[v]=distance[u]+w;
       }
        }
    }
    bool flag=false;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
       int v=edges[i][1];
       int w=edges[i][2];
       if(distance[u]!=INT_MAX && distance[u]+w<distance[v])
       {
                                                                                                                                                                            
        return{-1};
       }
    }
   
    return distance;
    

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
    bool flag=true;
   vector<int> ans= g1.belmanford(g1.edges,x,0);
   if(flag)
   {
   for(int i=0;i<ans.size();i++)
   {
    cout<<ans[i]<<" ";
   }
   }
    return 0;
}
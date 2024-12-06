#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include<stack>
#include<climits>
#include<queue>
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
                cout << p.first<< " "<<p.second<<" ";
            }
            cout << endl;
        }
    }
vector<int> dijisktra( unordered_map<int, vector<pair<int,int>>> adj ,int vertices,int source)
{
    vector<int> distance(vertices,INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    distance[source]=0;
    pq.push({0,source});
    while(!pq.empty())
    {
        int u=pq.top().second;
        int w=pq.top().first;
        pq.pop();
        if(w>distance[u])
        {
            continue;
        }
        for(auto &it:adj[u])
        {
            int v=it.first;
            int x=it.second;
            if(distance[u]!=INT_MAX &&distance[u]+x<distance[v])
            {
                 distance[v] = distance[u] + x;
                    pq.push({distance[v], v});
            }
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
    
  
   vector<int> ans= g1.dijisktra(g1.adj,x,0);
 
   for(int i=0;i<ans.size();i++)
   {
    cout<<ans[i]<<" ";
   }
  return 0;
}
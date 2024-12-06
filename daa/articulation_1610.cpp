#include <iostream>
#include <vector>
#include <fstream>
#include<unordered_map>
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
void dfs(int v, int i, int nodei, unordered_map<int, vector<int>> &adj, vector<int> &vis){
    vis[nodei]=1;
    for(auto k : adj[nodei]){
        if(k!=i){
            if(!vis[k]){
                dfs(v,i,k,adj,vis);
            }
        }
    }
}
void dfs(int v, int nodei, unordered_map<int, vector<int>> &adj, vector<int> &vis){
    vis[nodei]=1;
    for(auto k : adj[nodei]){
       
            if(!vis[k]){
                dfs(v,k,adj,vis);
           
        }
    }
}


void articulationpoint(int v, unordered_map<int, vector<int>> &adj ){
int components1=0;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++)
        {
          if(!vis[i])
          {
          components1++;
            dfs(v,i,adj,vis);
            }
            }
    for(int i=0;i<v;i++){
        int components=0;
        vector<int> vis(v,0);
        for(int j=0;j<v;j++){
            if(j!=i){
                if(!vis[j]){
                    components++;
                    dfs(v,i,j,adj,vis);
                }
            }
        }
        if(components>components1){
        cout<<i<<endl;
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
   
 
   
    fout<<"Articulation points: "<<endl;
    g1.articulationpoint(x,g1.adj);
    return 0;
}
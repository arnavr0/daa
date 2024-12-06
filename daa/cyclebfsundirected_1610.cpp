#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
class graph
{
    public:
    int E;
    int V;
    int a;
    unordered_map<int,vector<int>> adjlist;
    graph(int Edges,int a,int vertices)
    {
       this->E=Edges;
       this->a=0;
    }
    void addele()
    {
        cout<<"enter 1 for directed and 0 for undirected";
            cin>>a;
        for(int i=0;i<E;i++)
        {
            int u, v;
            cout<<"enter connected pair";
            cin>>u>>v;
            
            adjlist[u].push_back(v);
            if(a==0)
            {
            adjlist[v].push_back(u);
            }
        }
    }
    void print()
    {
       for(auto it:adjlist)
       {
        cout<<it.first<<"->";
        for(auto p:it.second)
        {
            cout<<p<<" ";
        }
        cout<<endl;
       }
    }
};
bool bfs1(unordered_map<int,vector<int>> adj,int vertices,vector<int>&visited,vector<int>parent)
{
    queue<int> q;
    q.push(vertices);
    visited[vertices]=1;
    while(!q.empty())
    {
        int k=q.front();
        cout<<k<<" ";
        q.pop();
        for(auto it:adj[k])
        {
            if(!visited[it])
            {
                parent[it]=vertices;
                q.push(it);
                visited[it]=1;
            }
            else if(parent[it]!=vertices)
            {
                return false;
            }
        }

    }
    return true;
}
void bfs(unordered_map<int,vector<int>> adj,int vertices)
{
    vector<int> visited(vertices,0);
    vector<int>parent (vertices,-1);
    for(int i=0;i<vertices;i++)
    {
        if(!visited[i])
        {
            bfs1(adj,i,visited,parent);
        }
    }
}
int main()
{
    int edges=5;
    int vertices=4;
    graph g1(edges,0,vertices);
    g1.addele();
    g1.print();
    bfs(g1.adjlist,vertices);
    
}
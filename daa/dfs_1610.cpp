#include<iostream>
#include<unordered_map>
#include<vector>
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
void dfs(unordered_map<int,vector<int>> adjlist,int vertices,vector<int>& visited,vector<int> &entrytime,vector<int> &exittime,int &time,unordered_map<int,vector<int>>&treenode, unordered_map<int,vector<int>> &backedge,unordered_map<int,vector<int>> &forward,unordered_map<int,vector<int>> &crossedge)
{
   visited[vertices]=1;
   time++;
   entrytime[vertices]=time;
   cout<<vertices<<" ";
   for(auto i:adjlist[vertices])
   {
       if(!visited[i])
       {
         treenode[vertices].push_back(i);
         dfs(adjlist,i,visited,entrytime,exittime,time,treenode,backedge,forward,crossedge);
       }
       else
       {
       
        if(entrytime[vertices]>entrytime[i] &&exittime[i]==0)
        {
            
            backedge[vertices].push_back(i);
        }
        else  if(entrytime[vertices]<entrytime[i] &&exittime[i]!=0  )
        {
            forward[vertices].push_back(i);
        }
        else
        {
            crossedge[vertices].push_back(i);
        }
       }
       
   }
   time++;
   exittime[vertices]=time;
}
int main()
{
    int edge=8,vertic=6;
    graph g1(edge,0,vertic);
    g1.addele();
    g1.print();
     vector<int> visited(vertic,0);
     vector<int> entrytime(vertic,0);
     vector<int> exittime(vertic,0);
     
     unordered_map<int,vector<int>> treenode;
      unordered_map<int,vector<int>> backedge;
       unordered_map<int,vector<int>> forward;
       unordered_map<int,vector<int>> crossedge;
     int time=0;
    for(int i=0;i<vertic;i++)
    {
        
        if(!visited[i])
        {
            
        dfs(g1.adjlist,i,visited, entrytime,exittime,time,treenode,backedge,forward,crossedge);
        }
    }
    cout<<"tree node"<<endl;
    for(auto it:treenode)
    {

        cout<<it.first<<"->";
        for(auto i:it.second)
        {
             cout<<i<<" ";
        }
        
        cout<<endl;
    }
    cout<<"back node"<<endl;
    for(auto it:backedge)
    {

        cout<<it.first<<"->";
        for(auto i:it.second)
        {
             cout<<i<<" ";
        }
        
        cout<<endl;
    }
    cout<<"forward edge :"<<endl;
     for(auto it:forward)
    {

        cout<<it.first<<"->";
        for(auto i:it.second)
        {
             cout<<i<<" ";
        }
        
        cout<<endl;
    }
    cout<<"cross edge :"<<endl;
     for(auto it:crossedge)
    {

        cout<<it.first<<"->";
        for(auto i:it.second)
        {
             cout<<i<<" ";
        }
        
        cout<<endl;
    }
    
    return 0;
}
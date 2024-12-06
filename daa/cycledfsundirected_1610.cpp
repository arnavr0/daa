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
bool cycle(unordered_map<int,vector<int>> adjlist,int vertices,vector<int>& visited,vector<int> &parent)
{
   visited[vertices]=1;
 
   cout<<vertices<<" ";
   for(auto i:adjlist[vertices])
   {
       if(!visited[i])
       {
         parent[i]=vertices;
         cycle(adjlist,i,visited,parent);
       }
       else{
        if(parent[vertices]!=i)
        {
            return true;
        }
       }
       
       
   }
   return false;
   
}
bool cyclep(int vertic,unordered_map<int,vector<int>> adjlist)
{
    vector<int>parent(vertic,-1);  
    vector<int> visited(vertic,0);   
    for(int i=0;i<vertic;i++)
    {
        
        if(!visited[i])
        {    
         if(cycle(adjlist,i,visited,parent))
         {
            return true;
         }
        }
        
    }
    return false;
}
int main()
{
    int edge=4,vertic=4;
    graph g1(edge,0,vertic);
    g1.addele();
    g1.print();
    bool p=cyclep(vertic,g1.adjlist);
    if(p==true)
    {
        cout<<"cycle detected";
    }
    else{
        cout<<"cycle undetected";
    }
    
    
    
    return 0;
}
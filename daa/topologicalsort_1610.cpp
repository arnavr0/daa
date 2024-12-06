#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<fstream>
using namespace std;
class graph
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
                if (val !=0)
                {
                    adj[i].push_back(j);
                }
            }
        }

        fin.close(); 
    }
    void print()
    {
       for(auto it:adj)
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
void  topological(int vertices,unordered_map<int,vector<int>> adjlist,vector<int>& visited,stack<int> &st)
{
   visited[vertices]=1;
 
   
   for(auto i:adjlist[vertices])
   {
       if(!visited[i])
       {
         
         topological(i,adjlist,visited,st);
       }
                   
   }
  st.push(vertices);
   
}
void bfs(int vertic,unordered_map<int,vector<int>> adjlist)
{
    stack<int>st;
    vector<int> visited(vertic,0);  
    for(int i=0;i<vertic;i++)
    {
       
        if(!visited[i])
        {    
         topological(i,adjlist,visited,st);
        }
       
    }
    while(!st.empty())
    {
    cout<<st.top()<<" ";
    st.pop();
    }
   
}
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
    graph g1;
    g1.addele();
  
    bfs(g1.vertices,g1.adj); 
    return 0;
    }

#include<bits/stdc++.h>
using namespace std;
//implement disjoint set
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
int main()
{
    int n = 5;
    DisjointSet ds(n);
};


#include<bits/stdc++.h>
using namespace std;

int naivesm(string P, string T)
{
    int p=P.length();
    int t=T.length();
    int count=0;
    for(int i=0; i<=(t-p); i++)
    {
        for(int j=0; j<p; j++)
        {
            if(P[j]!=T[i+j])
            {
                break;
            }
            if(j==p-1)
            {
                count++;
                cout<<"pattern matched at position "<<i<<" of text"<<endl;
            }
        }
    }
    return count;
}
int main()
{
    string P="aab";
    string T="acaabcaab";
    int count=naivesm(P,T);
    cout<<"count is "<<count;
    return 0;
}
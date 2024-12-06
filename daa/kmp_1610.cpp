#include<bits/stdc++.h>
using namespace std;
vector<int> prefix(string s)
{
    int m=s.length();
    vector<int>pi(m,0);
    int i=1;
    int len=0;
    while(i<m)
    {
        if(s[i]==s[len])
        {
            len++;
            pi[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=pi[len-1];
            }
            else
            {
                pi[i]=0;
                i++;
            }
        }
    }
    return pi;
}
void kmp(string T,string P)
{
    int m=T.length();
    int n=P.length();
    vector<int> pi=prefix(P);
    int i=0; 
    int j=0;
    while(i<m)
    {
        if(P[j]==T[i])
        {
            i++;
            j++;
            if(j==n)
            {
                cout<<"pattern matched at position "<<i-j<<endl;
            }
        }
        else
        {
            if(j!=0)
            {
                j=pi[j-1];
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    string P="aab";
    string T="acaabcaab";
    kmp(T,P);
    return 0;
}

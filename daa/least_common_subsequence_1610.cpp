#include<bits/stdc++.h>
using namespace std;
void  printlcs(vector<vector<string>> b,string s1,int i,int j)
{
       if(i==0 || j==0 || b[i][j]=="" )
       {
           return;
       }
       if(b[i][j]=="d")
       {
           printlcs(b,s1,i-1,j-1);
           cout<<s1[i-1];
       }
       else if(b[i][j]=="u")
       {
          printlcs(b,s1,i-1,j);
       }
       else if(b[i][j]=="s")
       {
         printlcs(b,s1,i,j-1);
       }
}
       
       
void lcs(string s1 ,string s2)
{
    int m=s1.length();
    int n=s2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    vector<vector<string>>b(m+1,vector<string>(n+1,""));
    for(int i=1;i<=m;i++)
    {
       for(int j=1;j<=n;j++)
       {
          if(s1[i-1]==s2[j-1])
          {
             dp[i][j]=dp[i-1][j-1]+1;
              b[i][j]="d";
          }
          else
          {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(dp[i-1][j]>dp[i][j-1])
            {
               b[i][j]="u";
            }
            else
            {
              b[i][j]="s";
            }
          }
        }
      }
      
      printlcs(b,s1,m,n);
}
     int main() {
    string X = "abccba";
    string Y = "abddba";

    lcs(X, Y);

   
    return 0;
}

 

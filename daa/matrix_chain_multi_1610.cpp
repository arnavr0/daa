#include <bits/stdc++.h> 
using namespace std;
int matrixMultiplication(vector<int>&arr,int N)
{    
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i=N-1; i>=1; i--) {
        for (int j=i+1; j<N; j++) {
            dp[i][j] = INT_MAX;
            for (int k=i; k<j; k++)
                dp[i][j] = min(dp[i][j], arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j]);
        }
    }
    return dp[1][N-1];
}
int main() {
     ofstream fout;
    cout<<"enter number of elements";
    int x;
    cin>>x;
    fout.open("numbers.txt");
    for(int i=0;i<x;i++)
    {
        int v;
        cin>>v;
        fout<<v<<endl;
    }
    fout.close();
    ifstream fin;
    fin.open("numbers.txt");
    vector<int> arr;
    int value;
    while(fin>>value)
    {
       arr.push_back(value);
    }
    fin.close();
    
    int result = matrixMultiplication(arr, x);
    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}
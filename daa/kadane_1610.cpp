#include<bits/stdc++.h>
using namespace std;

long long maxsubarraysum(vector<int>& arr, int n) {
    long long sum = 0, maxi = LLONG_MIN;
    int start = 0, end = -1, tempStart = 0;
    int ansstart=-1;
   
    for(int i = 0; i < n; i++) {
       
        if(sum==0)
        {
        start=i;
       
        }
        sum += arr[i];
       if(sum>maxi)
       {
         maxi=sum;
         ansstart=start;
            end=i;
       }
       
        if (sum <=0) {
            sum = 0;  
           
        }
    }
   
   cout<<ansstart<<" "<<end<<" ";
    return maxi;
}

int main() {
    ifstream fin;
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
    fin.open("numbers.txt");
    vector<int> arr;
    int value;
    while(fin>>value)
    {
       arr.push_back(value);
    }
    fin.close();
    long long ans = maxsubarraysum(arr, arr.size());
    cout << "Maximum subarray sum: " << ans << endl;
}
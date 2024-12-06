#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> countinv(vector<int> arr)
{
vector<pair<int,int>> ans;
  int n=arr.size();
  for(int i=0;i<n;i++)
  {
     for(int j=i+1;j<n;j++)
     {
        if(arr[i]>arr[j])
        {
            ans.push_back({arr[i],arr[j]});
        }
    }
 }
     return ans;
}

int main()
{
  ofstream fout;
  int n;
  cin>>n;
  fout.open("numbers.txt");
  fout<<n;
  fout<<endl;
  vector<int> arr(n,0);
  for(int i=0;i<n;i++)
  {
     cin>>arr[i];
     fout<<arr[i]<<" ";
 }
 fout.close();
 ifstream fin;
 fin.open("numbers.txt");
 int elements;
 fin>>elements;
 vector<int> arr1(elements,0);
 for(int i=0;i<elements;i++)
 {
    fin>>arr1[i];
 }
 
 vector<pair<int,int>> ans=countinv(arr1);
 cout<<"no of inversion pair : "<<ans.size()<<endl;
 cout<<"inversion pair are : "<<endl;
 for(auto it:ans)
 {
    cout<<it.first<<" "<<it.second<<endl;
 }
 fin.close();
 return 0;
}

    
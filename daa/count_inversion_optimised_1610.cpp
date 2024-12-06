#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr,int start,int mid,int end,int &count)
{
  vector<int> temp;
  int i=start;
  int j=mid+1;
  while(i<=mid && j<=end)
  {
     if(arr[i]<=arr[j])
     {
        temp.push_back(arr[i]);
        i++;
     }
     else
     {
     
       
       temp.push_back(arr[j]);
       count+=(mid-i+1);
       j++;
   }
  }
  while(i<=mid)
  {
     temp.push_back(arr[i]);
     i++;
  }
  while(j<=end)
  {
   temp.push_back(arr[j]);
     j++;
  }
    for (int k= start; k <= end; k++) {
        arr[k] = temp[k - start];
    }
     
     
       
}
void mergesort(int start,int end,vector<int> &arr,int &count)
{
   if(start>=end)
   {
     return;
   }
   int mid=start+(end-start)/2;
   mergesort(start,mid,arr,count);
   mergesort(mid+1,end,arr,count);
   merge(arr,start,mid,end,count);
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
 

 int count=0;
 mergesort(0,n-1,arr,count);
 cout<<"no of inversion pair are : "<<count<<endl;

 fin.close();
 return 0;
}
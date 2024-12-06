#include<iostream>
#include<vector>
using namespace std;
int pivot(vector<int> &arr,int start)
{
   int n=arr.size();
   int pivot=n-1;
   int j=start-1;
   for(int i=0;i<n;i++)
   {
       if(arr[i]<arr[pivot])
       {
          j++;
          swap(arr[i],arr[j]);
       }
    }
    swap(arr[j+1],arr[pivot]);
    return j+1;
}
int main()
{
   vector<int> arr;
   int n;
   cout<<"enter number of elements";
   cin>>n;
   for(int i=0;i<n;i++)
   {
      int x;
      cout<<"enter elements";
      cin>>x;
      arr.push_back(x);
   }
   int temp=arr[n-1];
   arr[n-1]=0;
   int m=pivot(arr,0);
   arr[m]=temp;
   if(arr[m]<0)
   {
    m=m+1;
   }
   for(int i=1;i<m&&m<arr.size();i+=2)
   {
      swap(arr[i],arr[m++]);
    }
   
    for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
}
#include<iostream>
using namespace std;
void zeroes(int arr[],int &count,int start,int high)
{
   int mid=(start+high)/2;
   if(start<=high)
   {
   if(arr[mid]==0)
   {
      count++;
   }
   zeroes(arr,count,start,mid-1);
   zeroes(arr,count,mid+1,high);
   }
}

int main() {
    int n;
    cout<<"enter elements";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
    }
   int count=0;
   
    zeroes( arr,count,0,n-1);
   
   
    cout<<"count "<<count<<endl;
    return 0;
}

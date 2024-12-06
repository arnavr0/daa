#include<iostream>
using namespace std;
bool nby2counts(int arr[],int &count,int start,int high,int k,int n)
{
   int mid=(start+high)/2;
   if(start<=high)
   {
   if(arr[mid]==k)
   {
      count++;
      if(count>n/2)
      {
        return true;
      }
      
   }
   nby2counts(arr,count,start,mid-1,k,n);
   nby2counts(arr,count,mid+1,high,k,n);
   }
   return false;
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
    int k;
    cout<<"enter elements which we have to find :";
    cin>> k;
    cout<<endl;
   int count=0;
   
    bool p=nby2counts( arr,count,0,n-1,k,n);
    cout<<"count "<<count<<endl;
    cout<<p<<endl;
    if(p==true)
    {
        cout<<"condition satisfied";
    }
    else{
        cout<<"condition not satisfied";
    }
   cout<<endl;
   
    
    return 0;
}

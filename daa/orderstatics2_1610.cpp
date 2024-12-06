#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int  partition1(int arr[],int start,int end)
{
    int pivot=arr[end];
    
    int j=start-1;
 for(int i=start;i<end;i++)
    {
        if(arr[i]<pivot)
        {
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[end]);
    return j+1;   
}
int randomizedPartition(int arr[], int low, int high) {
    int n = high - low + 1;
    int pivot = rand() % n;
    swap(arr[low + pivot], arr[high]);
    return partition1(arr, low, high);
}
int  randomisedselect(int arr[],int start,int end,int i)
{
    if(start==end)
    {
        return arr[start];
    }
    int q=randomizedPartition(arr,start,end);
    int k=q-start+1;
    if(i==k)
    {
        return arr[q];
    }
    else if(i<k)
    {
        return randomisedselect(arr,start,q-1,i);
    }
    return randomisedselect(arr,q+1,end,i-k);
}
int  partition(int arr[],int start,int end,int k)
{
    int i;
    for(i=start;i<end;i++)
    {
        if(arr[i]==k)  
        {
            break;
        }
    }
    swap(arr[i],arr[end]);
    
    int j=start-1;
 for( i=start;i<end;i++)
    {
        if(arr[i]<=k)
        {
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[end]);
    return j+1;   
}
int findMedian(int arr[],int p)
{
    sort(arr,arr+p);
    return arr[p/2];
}
int mom(int arr[],int low,int high,int k)
{
    
    int n=high-low+1;
    int median[(n+4)/5];
    int i;
    for( i=0;i<n/5;i++)
    {
        median[i]=findMedian(arr+low+i*5,5);
    }
    if(i*5<n)
        {
            median[i]=findMedian(arr+low+i*5,n%5);
            i++;
        }
        int g=(n+4)/5;

  	int medofmedian = randomisedselect(median,0,g-1,(g/2)+1);
 cout<<medofmedian<<" ";
    int pos=partition(arr,low,high,medofmedian);
    if(pos-low==k-1)
    {
        return arr[pos];
    }    
    if(pos-low>k-1)
    {
        return mom(arr,low,pos-1,k);
    }
    else
    {
        return mom(arr,pos+1,high,k-pos+low-1);
    }
    
}
int main()
{
    

    cout<<"enter number of elements";
    int x;
    cin>>x;
     int arr[x];
    for(int i=0;i<x;i++)
    {
        int v;
        cin>>v;
         arr[i]=v;
       
    }
    for(int i=0;i<x;i++)
    {
        cout<<arr[i]<<" ";
    }
  
   int end=x-1;
   int p;
   cout<<"Enter which smallest element we found : ";
   cin>>p;

   
    
    int c=mom(arr,0,end,p);
    cout<<p<<" smallest element is : "<<c<<endl;
    
}
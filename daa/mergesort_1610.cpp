#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
void merge(vector<int> &arr,int start,int end,int mid)
{
    int n2=end-mid;
    int n1=mid-start+1;
    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++)
    {
        arr1[i]=arr[i+start];
    }
    for(int i=0;i<n2;i++)
    {
        arr2[i]=arr[i+mid+1];
    }
    int i=0,j=0;
    int k=start;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            k++;
            i++;
        }
        else 
        {
            arr[k]=arr2[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=arr1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=arr2[j];
        k++;
        j++;
    }
}
void mergesort(vector<int> & arr,int start,int end)
{
    if(start<end)
    {
        int mid=start+(end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,end,mid);
    }
    
}
int main()
{
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
    
    mergesort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    
    fout.open("numbers.txt");
    int i=0;
    while(i<arr.size())
    {
        fout<<arr[i]<<endl;
        i++;
    }
    fout.close();
    

}
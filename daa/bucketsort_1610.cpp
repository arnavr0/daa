#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void insertionsort(vector<float> & arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        float key=arr[i];
        while(j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void bucketsort(float arr[],int n)
{
    vector<float> b[n];
    for(int i=0;i<n;i++)
    {
        int c=n*arr[i];
        if (c >= n) c = n - 1;
        b[c].push_back(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        insertionsort(b[i]);
    }
    int index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            arr[index++]=b[i][j];
        }
    }

}
int main()
{
    ifstream fin;
    ofstream fout;
    cout<<"enter number of elements";
    int x;
    cin>>x;
    fout.open("numbers.txt");
    for(int i=0;i<x;i++)
    {
        
        float v;
        cin>>v;
        fout<<v<<endl;
    }
    fout.close();
    fin.open("numbers.txt");
    float arr[x];
    int i=0;
    float value;
    while(fin>>value)
    {
       arr[i]=value;
       i++;
    }
    fin.close();
    
    //float arr[]={0.897,0.565,0.656,0.1234,0.665,0.3434};
     // int n=sizeof(arr)/sizeof(arr[0]);
    bucketsort(arr,x);
  
    for(int i=0;i<x;i++)
    {
        cout<<arr[i]<<" ";
    }
}
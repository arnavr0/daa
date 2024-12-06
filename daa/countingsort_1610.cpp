#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
void countingsort(vector<int> & arr)
{
    int n=arr.size();
    int maxi=arr[0];
    for(int i=0;i<n;i++)
    {
        if(maxi<arr[i])
        {
            maxi=arr[i];
        }
    }
    vector<int> freq(maxi+1,0);
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(int i=1;i<=maxi;i++)
    {
        freq[i]=freq[i]+freq[i-1];
    }
    vector<int> output(n);
    for(int i=n-1;i>=0;i--)
    {
        output[(freq[arr[i]]-1)]=arr[i];
        freq[arr[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
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
    
    countingsort(arr);
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
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
void bubblesort(vector<int> & arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                swap(arr[j],arr[j+1]);
            }
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
    
    bubblesort(arr);
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
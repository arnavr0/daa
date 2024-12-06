#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void countingsort(vector<int> & arr,int place)
{
    int n=arr.size();
    vector<int> freq(10,0);
    for(int i=0;i<n;i++)
    {
        freq[(arr[i]/place)%10]++;
    }
    for(int i=1;i<10;i++)
    {
        freq[i]=freq[i]+freq[i-1];
    }
    vector<int> output(n);
    for(int i=n-1;i>=0;i--)
    {
        output[(freq[(arr[i]/place)%10]-1)]=arr[i];
        freq[(arr[i]/place)%10]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }

    
}
void radixsort(vector<int> &arr)
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
    for(int place=1;maxi/place>0;place*=10)
    {
        countingsort(arr,place);
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
    
    radixsort(arr);
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
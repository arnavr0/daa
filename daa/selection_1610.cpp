#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
void selectionsort(vector<int> & arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(arr[i],arr[min]);
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
    
    selectionsort(arr);
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
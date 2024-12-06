#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
//linear search algorithm
int linearsearch(vector<int> arr,int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
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
    int target;
    cout<<"target element";
    cin>>target;
    int index1=linearsearch(arr,x,target);  
    cout<<"index1 "<<index1<<endl;
    return 0;
}

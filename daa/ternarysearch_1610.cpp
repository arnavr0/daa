#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
// ternary search algorithm
int ternarysearch(vector<int> arr,int n, int target)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid1=start+(end-start)/3;
        int mid2=end-(end-start)/3;
        if(arr[mid1]==target)
        {
            return mid1;
        }
        if(arr[mid2]==target)
        {
            return mid2;
        }
        if(arr[mid1]>target)
        {
            end=mid1-1;
        }
        else if(arr[mid2]<target)
        {
            start=mid2+1;
        }
        else
        {
            start=mid1+1;
            end=mid2-1;
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
    cout<<"enter target element "<<" ";
    cin>>target;
   // sort array that array is input for ternary
    sort(arr.begin(),arr.end());
    cout<<endl;
    
    int index1=ternarysearch(arr,x,target);
    cout<<"index1 "<<index1<<endl;


    return 0;
}

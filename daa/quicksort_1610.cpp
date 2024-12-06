#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
int quick(vector<int> &arr,int start,int end)
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
void quicksort(vector<int> & arr,int start,int end)
{
    if(start<end)
    {
        int pivot=quick(arr,start,end);
        
        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
    
}
int main()
{
    ifstream fin;
    fin.open("numbers.txt");
    vector<int> arr;
    int value;
    while(fin>>value)
    {
       arr.push_back(value);
    }
    fin.close();
    
    quicksort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    ofstream fout;
    fout.open("numbers.txt");
    int i=0;
    while(i<arr.size())
    {
        fout<<arr[i]<<endl;
        i++;
    }
    fout.close();
    

}
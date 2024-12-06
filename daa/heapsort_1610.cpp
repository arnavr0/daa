
#include <iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
 
    if (largest != i) {

        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
 
void heapSort(vector<int>& arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
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
    int n=arr.size();
     for(int i=n/2 -1;i>=0;i--){
       heapify(arr,n,i);
   }
   
  cout << "After heapifying array is \n";
    printArray(arr, n);
   
   
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
     
  return 0;
}
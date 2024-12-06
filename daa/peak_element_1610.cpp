#include <iostream>
#include<vector>
#include<fstream>
using namespace std;


int findPeak(vector<int> arr, int low, int high, int n) {
    int mid = low + (high - low) / 2;
    
   
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
        return mid;
    }
    
    
    else if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return findPeak(arr, low, mid - 1, n);
    }
    
    
    else {
        return findPeak(arr, mid + 1, high, n);
    }
}

int main() {
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
    
    int peakIndex = findPeak(arr, 0, x - 1, x);
    
    cout << "Peak element is at index: " << peakIndex << endl;
    cout << "Peak element is: " << arr[peakIndex] << endl;
    
    return 0;
}


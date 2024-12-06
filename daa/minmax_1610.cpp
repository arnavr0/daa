#include <iostream>
#include <algorithm>
#include<vector>
#include<fstream>
using namespace std;


void findMinMax(vector<int> arr, int low, int high, int &minVal, int &maxVal) {
  
    if (low == high) {
        minVal = maxVal = arr[low];
        return;
    }
    
   
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            minVal = arr[low];
            maxVal = arr[high];
        } else {
            minVal = arr[high];
            maxVal = arr[low];
        }
        return;
    }
    
    
    int mid = (low + high) / 2;
    
    
    int minLeft, maxLeft;
    int minRight, maxRight;
    
    
    findMinMax(arr, low, mid, minLeft, maxLeft);
    findMinMax(arr, mid + 1, high, minRight, maxRight);
    
   
    minVal = min(minLeft, minRight);
    maxVal = max(maxLeft, maxRight);
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
    
    int minVal, maxVal;
    
    findMinMax(arr, 0, x- 1, minVal, maxVal);
    
    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
    
    return 0;
}


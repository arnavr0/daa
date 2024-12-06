#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted arrays
vector<int> mergetwosorted(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }
    
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }
    
    return merged;
}

// Function to merge k sorted arrays using divide-and-conquer
vector<int> mergeksorted(vector<vector<int>>& arrays, int left, int right) {
    if (left == right) {
        return arrays[left];
    }
    
    if (left + 1 == right) {
        return mergetwosorted(arrays[left], arrays[right]);
    }
    
    int mid = left + (right - left) / 2;
    vector<int> leftMerged = mergeksorted(arrays, left, mid);
    vector<int> rightMerged = mergeksorted(arrays, mid + 1, right);
    
    return mergetwosorted(leftMerged, rightMerged);
}

int main() {
    vector<vector<int>> arrays = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6},{5,6,7,8}
    };
    
    vector<int> result = mergeksorted(arrays, 0, arrays.size() - 1);
    
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}
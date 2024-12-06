#include <iostream>
#include <vector>

using namespace std;

// Function to merge three sorted subarrays
void merge(vector<int>& array, int low, int mid1, int mid2, int high) {
    vector<int> temp;
    int i = low, j = mid1, k = mid2;

    // Traverse the three subarrays and add the smallest element to the temp array
    while (i < mid1 && j < mid2 && k < high) {
        if (array[i] < array[j]) {
            if (array[i] < array[k]) {
                temp.push_back(array[i++]);
            } else {
                temp.push_back(array[k++]);
            }
        } else {
            if (array[j] < array[k]) {
                temp.push_back(array[j++]);
            } else {
                temp.push_back(array[k++]);
            }
        }
    }

    // Traverse the remaining elements
    while (i < mid1 && j < mid2) {
        if (array[i] < array[j]) {
            temp.push_back(array[i++]);
        } else {
            temp.push_back(array[j++]);
        }
    }

    while (j < mid2 && k < high) {
        if (array[j] < array[k]) {
            temp.push_back(array[j++]);
        } else {
            temp.push_back(array[k++]);
        }
    }

    while (i < mid1 && k < high) {
        if (array[i] < array[k]) {
            temp.push_back(array[i++]);
        } else {
            temp.push_back(array[k++]);
        }
    }

    // Copy the remaining elements
    while (i < mid1) {
        temp.push_back(array[i++]);
    }

    while (j < mid2) {
        temp.push_back(array[j++]);
    }

    while (k < high) {
        temp.push_back(array[k++]);
    }

    // Copy the sorted elements back into the original array
    for (int i = low; i < high; ++i) {
        array[i] = temp[i - low];
    }
}

// Function to perform 3-way merge sort
void mergeSort3Way(vector<int>& array, int low, int high) {
    if (high - low < 2) {
        return;
    }

    int third = (high - low) / 3;
    int mid1 = low + third;
    int mid2 = low + 2 * third + 1;

    mergeSort3Way(array, low, mid1);
    mergeSort3Way(array, mid1, mid2);
    mergeSort3Way(array, mid2, high);

    merge(array, low, mid1, mid2, high);
}

int main() {
    vector<int> array ;
    int c;
    cout<<"enter number of elements";
    cin>>c;
    for(int i=0;i<c;i++)
    {
        int x;
        cout<<"enter value :";
        cin>>x;
        array.push_back(x);
    }

    cout << "Given array is \n";
    for (int i : array) {
        cout << i << " ";
    }
    cout << endl;

    mergeSort3Way(array, 0, array.size());

    cout << "Sorted array is \n";
    for (int i : array) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

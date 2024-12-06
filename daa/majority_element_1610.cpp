#include <iostream>
#include <vector>
using namespace std;

// Function to find the majority element in a subarray using divide and conquer
int majorityElement(vector<int>& arr, int low, int high) {
    // Base case: if the subarray has only one element, return that element
    if (low == high) {
        return arr[low];
    }

    // Divide the array into two halves
    int mid = (low + high) / 2;

    // Recursively find the majority element in both halves
    int leftMajority = majorityElement(arr, low, mid);
    int rightMajority = majorityElement(arr, mid + 1, high);

    // If both halves agree on the majority element, return it
    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    // Otherwise, count each element and return the one that is a majority
    int leftCount = 0;
    int rightCount = 0;
    for (int i = low; i <= high; ++i) {
        if (arr[i] == leftMajority) leftCount++;
        if (arr[i] == rightMajority) rightCount++;
    }

    return (leftCount > rightCount) ? leftMajority : rightMajority;
}

// Function to check if x is a majority element
bool isMajority(vector<int>& arr, int n, int x) {
    // Find the majority element using divide and conquer
    int majorityElem = majorityElement(arr, 0, n - 1);

    // Check if the found majority element is the same as x and if it's a majority
    if (majorityElem == x) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == x) count++;
        }
        return count > n / 2;
    }

    return false;
}

int main() {
    vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = arr.size();
    int x = 4;

    if (isMajority(arr, n, x)) {
        cout << x << " is a majority element." << endl;
    } else {
        cout << x << " is not a majority element." << endl;
    }

    x = 3;
    if (isMajority(arr, n, x)) {
        cout << x << " is a majority element." << endl;
    } else {
        cout << x << " is not a majority element." << endl;
    }

    return 0;
}

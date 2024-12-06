#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

// Function to find the k-th element in two sorted arrays using binary search
int findKthElement(int arr1[], int n, int arr2[], int m, int k) {
    if (n > m) {
        return findKthElement(arr2, m, arr1, n, k);
    }

    int low = max(0, k - m), high = min(k, n);

    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1;

        int l1 = (mid1 == 0) ? INT_MIN : arr1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : arr2[mid2- 1];
        int r1 = (mid1 == n) ? INT_MAX : arr1[mid1];
        int r2 = (mid2== m) ? INT_MAX : arr2[mid2];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return -1; // This line is never reached if k is a valid input
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = 5;
    
    cout << "The " << k << "-th element is " << findKthElement(arr1, n, arr2, m, k) << endl;
    
    return 0;
}
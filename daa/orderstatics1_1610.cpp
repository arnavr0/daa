#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to partition the array and return the position of the pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

// Randomized partition function to avoid worst-case scenarios
int randomisedpartition(int arr[], int low, int high) {
    int n = high - low + 1;
    int pivot = rand() % n;
    swap(arr[low + pivot], arr[high]);
    return partition(arr, low, high);
}

// Function to implement the SELECT algorithm to find the ith smallest element
int randomisedselect(int arr[], int low, int high, int i) {
    if (low == high) {
        return arr[low];
    }

    int q = randomisedpartition(arr, low, high);
    int k = q - low + 1;

    if (i == k) {
        return arr[q];
    } else if (i < k) {
        return randomisedselect(arr, low, q - 1, i);
    } else {
        return randomisedselect(arr, q + 1, high, i - k);
    }
}

// Function to find the kth largest element by using the SELECT algorithm
int findkthlargest(int arr[], int n, int k) {
    // Finding kth largest is equivalent to finding (n-k+1)th smallest
    return randomisedselect(arr, 0, n - 1, n - k + 1);
}

int main() {
    srand(time(0)); // Seed for random number generation

    int arr[] = {12, 3, 5, 7, 19, 26, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int i = 3; // Find the 3rd smallest element
    cout << "The " << i << "rd smallest element is " << randomisedselect(arr, 0, n - 1, i) << endl;

    int k = 2; // Find the 2nd largest element
    cout << "The " << k << "nd largest element is " << findkthlargest(arr, n, k) << endl;

    return 0;
}
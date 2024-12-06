#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int median(int arr1[], int n, int arr2[], int m) {
    if (n > m) {
        return median(arr2, m, arr1, n);
    }

    int low = 0, high = n;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n+m+1)/2-cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            if((n+m)%2==0){
                return (max(l1, l2)+min(r1,r2))/2;
            }
        else{
            return max(l1,l2);
        }
        }
       
       
        if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return -1;
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
   
    cout << "The median element is: " << median(arr1, n, arr2, m) << endl;
   
    return 0;
}


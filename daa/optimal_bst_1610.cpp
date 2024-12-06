#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int optimalBST(const vector<int>& keys, const vector<int>& freq)
{
    int n = keys.size();
    vector<vector<int>> cost(n, vector<int>(n, 0));
    vector<vector<int>> sum(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        sum[i][i] = freq[i];
    }
    for (int length = 2; length <= n; length++) {
        for (int i =  0; i <= n - length; i++) {
            int j = i + length - 1;
            sum[i][j] = sum[i][j - 1] + freq[j];
        }
    }
   
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum[i][j];
                cost[i][j] = min(cost[i][j], c);
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    vector<int> keys = {10, 20, 30};
    vector<int> freq = {34, 8, 50};

    cout << "Minimum cost of the Optimal BST is: " << optimalBST(keys, freq) << endl;
    return 0;
}

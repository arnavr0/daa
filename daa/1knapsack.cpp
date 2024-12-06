#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> wt, vector<int> p, int n)
{
    int i, j;
    vector<vector<int> > K(n + 1, vector<int>(W + 1));
    vector<vector<int>> b(n + 1, vector<int>(W + 1, 0));

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)    
            {
                K[i][j] = 0;
            }
            else if (wt[i - 1] <= j)  
            {
                if (p[i - 1] + K[i - 1][j - wt[i - 1]] > K[i - 1][j])
                {
                    K[i][j] = p[i - 1] + K[i - 1][j - wt[i - 1]];
                    b[i][j] = 1;
                }
                else
                {
                    K[i][j] = K[i - 1][j];
                    b[i][j] = 0; 
                }
            }
            else
            {
                K[i][j] = K[i - 1][j];
                b[i][j] = 0;
            }
        }
    }


    cout << "Items included: ";
    int w = W;
    for (i = n; i > 0; i--)
    {
        if (b[i][w] == 1)
        {
            cout << i << " ";
            w -= wt[i - 1];  
        }
    }
    cout << endl;

    return K[n][W];
}

int main()
{
    
    vector<int> profit = {3, 4, 5, 6};
    vector<int> weight = {2, 3, 4, 5};
    int W = 10;
    int n = profit.size();

    cout << "Max Profit Possible: " << knapSack(W, weight, profit, n) << endl;

    return 0;
}

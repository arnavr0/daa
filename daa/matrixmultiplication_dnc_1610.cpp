#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> add(vector<vector<int>> const &A, vector<vector<int>> const &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> matrixmultiplication(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    
    vector<vector<int>> C(n, vector<int>(n, 0));

    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        int k = n / 2;
        
        vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));
        vector<vector<int>>  B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));
        
        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + k];
                A21[i][j] = A[i + k][j];
                A22[i][j] = A[i + k][j + k];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + k];
                B21[i][j] = B[i + k][j];
                B22[i][j] = B[i + k][j + k];
            }
        }
        vector<vector<int>> C11=add(matrixmultiplication(A11,B11,n/2),matrixmultiplication(A12,B21,n/2));
        vector<vector<int>> C12=add(matrixmultiplication(A11,B12,n/2),matrixmultiplication(A12,B22,n/2));
        vector<vector<int>> C21=add(matrixmultiplication(A21,B11,n/2),matrixmultiplication(A22,B21,n/2));
        vector<vector<int>> C22=add(matrixmultiplication(A21,B12,n/2),matrixmultiplication(A22,B22,n/2));

        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                C[i][j] = C11[i][j];
                C[i][j + k] = C12[i][j];
                C[i + k][j] = C21[i][j];
                C[i + k][j + k] = C22[i][j];
            }
        }

    }
    return C;
}
int main()
{
    int n;
    cout << "Enter the size of the matrices: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));
    cout << "Enter matrix A:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter matrix B:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> C = matrixmultiplication(A, B,n);

    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
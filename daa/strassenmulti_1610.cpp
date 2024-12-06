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

vector<vector<int>> subtract(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int>> multiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        int k = n / 2;
        
        vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));
        vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));
        vector<vector<int>> C11(k, vector<int>(k)), C12(k, vector<int>(k)), C21(k, vector<int>(k)), C22(k, vector<int>(k));
        vector<vector<int>> P1(k, vector<int>(k)), P2(k, vector<int>(k)), P3(k, vector<int>(k)), P4(k, vector<int>(k));
        vector<vector<int>> P5(k, vector<int>(k)), P6(k, vector<int>(k)), P7(k, vector<int>(k));
        vector<vector<int>> S1(k,vector<int>(k)), S2(k,vector<int>(k)), S3(k,vector<int>(k)), S4(k,vector<int>(k)), S5(k,vector<int>(k));
        vector<vector<int>> S6(k,vector<int>(k)), S7(k,vector<int>(k)), S8(k,vector<int>(k)), S9(k,vector<int>(k)), S10(k,vector<int>(k));
        
        
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
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
        S1=subtract(B12,B22);
        S2=add(A11,A12);
        S3=add(A21,A22);
        S4=subtract(B21,B11);
        S5=add(A11,A22);
        S6=add(B11,B22);
        S7=subtract(A12,A22);
        S8=add(B21,B22);
        S9=subtract(A11,A21);
        S10=add(B11,B12);

        P1 = multiply(A11,S1);
        P2 = multiply(S2,B22);
        P3 = multiply(S3,B11);
        P4 = multiply(A22,S4);
        P5 = multiply(S5,S6);
        P6 = multiply(S7,S8);
        P7 = multiply(S9,S10);

        C11 = subtract(add(add(P5,P4),P6),P2);
        C12 = add(P1, P2);
        C21 = add(P3, P4);
        C22 = subtract(add(P5,P1), add(P3,P7));

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

int main() {
    int n;
    cout << "Enter the size of the matrices ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));
    cout << "Enter matrix A " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<"enter value ";
            cin >> A[i][j];
        }
    }

    cout << "Enter matrix B " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<"enter value ";
            cin >> B[i][j];
        }
    }

    vector<vector<int>> C = multiply(A, B);

    cout << "Resultant matrix " << endl;
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
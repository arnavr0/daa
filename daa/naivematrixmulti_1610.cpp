#include <iostream>
using namespace std;

void multiplyMatrices(int rows1, int cols1, int mat1[][10], int rows2, int cols2, int mat2[][10], int result[][10]) {
    // Initialize result matrix to 0
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions of the first matrix
    cout << "Enter rows and columns of the first matrix: ";
    cin >> rows1 >> cols1;

    // Input dimensions of the second matrix
    cout << "Enter rows and columns of the second matrix: ";
    cin >> rows2 >> cols2;

    // Check if multiplication is possible
    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible. Columns of the first matrix must equal rows of the second matrix.\n";
        return 1;
    }

    int mat1[10][10], mat2[10][10], result[10][10];

    // Input elements of the first matrix
    cout << "Enter elements of the first matrix:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cin >> mat1[i][j];
        }
    }

    // Input elements of the second matrix
    cout << "Enter elements of the second matrix:\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cin >> mat2[i][j];
        }
    }

    // Multiply matrices
    multiplyMatrices(rows1, cols1, mat1, rows2, cols2, mat2, result);

    // Display the result
    cout << "Resultant matrix:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

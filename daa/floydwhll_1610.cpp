#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjMatrix;

    void addele() {
        ifstream fin("numbers.txt");
        if (!fin.is_open()) {
            cout << "Error: Unable to open file." << endl;
            return;
        }

        fin >> vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, INT_MAX));
        int val;

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                fin >> val;
                if (val != 0) {
                    adjMatrix[i][j] = val;
                }
                if (i == j) {
                    adjMatrix[i][j] = 0; 
                }
            }
        }

        fin.close();
    }

    void printMatrix(const vector<vector<int>> &matrix) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (matrix[i][j] == INT_MAX) {
                    cout << "INF ";
                } else {
                    cout << matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    void floydWarshall() {
        vector<vector<int>> dist = adjMatrix;

       
        for (int k = 0; k < vertices; k++) {
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Print the result
        cout << "Shortest path matrix:" << endl;
        printMatrix(dist);

        // Check for negative weight cycles
        for (int i = 0; i < vertices; i++) {
            if (dist[i][i] < 0) {
                cout << "Negative weight cycle detected." << endl;
                return;
            }
        }
    }
};

int main() {
    ofstream fout;
    cout << "Enter number of vertices: ";
    int x;
    cin >> x;
    vector<vector<int>> ad(x, vector<int>(x));
    fout.open("numbers.txt");
    if (!fout.is_open())
    {
        cout << "Error: Unable to open file for writing." << endl;
        return 1;
    }
    fout << x << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> ad[i][j]; 
            fout << ad[i][j];
            if (j < x - 1)
            {
                fout << " "; 
            }
        }
        fout << endl; 
    }

    fout.close(); 
    Graph g1;
    g1.addele();

    cout << "Input Adjacency Matrix:" << endl;
    g1.printMatrix(g1.adjMatrix);

    g1.floydWarshall();

    return 0;
}

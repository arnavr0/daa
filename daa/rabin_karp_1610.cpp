#include <iostream>
#include <string>
using namespace std;

#define d 256  

void rabinKarp(string text, string pattern, int prime) {
    int m = pattern.size();
    int n = text.size();
    int i, j;
    int p = 0;  // Hash value for the pattern
    int t = 0;  // Hash value for the text
    int h = 1;  // Value of d^(m-1) % prime

    // Compute h = pow(d, m-1) % prime
    for (i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    // Compute initial hash values for pattern and text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % prime;
        t = (d * t + text[i]) % prime;
    }

    // Slide the pattern over the text
    for (i = 0; i <= n - m; i++) {
       
        if (p == t) {
            
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)  
                cout << "Pattern found at index " << i << endl;
        }

        // Compute hash for the next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % prime;
            // Handle negative hash value
            if (t < 0)
                t = (t + prime);
        }
    }
}

int main() {
    string text, pattern;
    int prime = 101; 

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    rabinKarp(text, pattern, prime);

    return 0;
}

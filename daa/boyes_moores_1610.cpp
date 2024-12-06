#include <iostream>
#include <string>
#include <vector>
using namespace std;
void preprocess(string pattern, vector<int>& bad) {
    int m = pattern.size();

   
    fill(bad.begin(), bad.end(), -1);

    //last occurence of each cahracter
    for (int i = 0; i < m; i++) {
        bad[pattern[i]] = i;
    }
}

void boyerMoore(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    // Create the bad character table
    vector<int> bad(256, -1);
    preprocess(pattern, bad);

    int s = 0; 
    while (s <= (n - m)) {
        int j = m - 1;

        // Match the pattern with the text from right to left
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        // If the pattern is found
        if (j < 0) {
            cout << "Pattern found at index " << s << endl;

            // Shift the pattern so the next character in the text aligns with the last occurrence in the pattern
            // If the next character is not in the pattern, shift by m
            s += (s + m < n) ? m - bad[text[s + m]] : 1;
        } else {
            // Shift the pattern based on the bad character rule
            s += max(1, j - bad[text[s + j]]);
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    boyerMoore(text, pattern);

    return 0;
}

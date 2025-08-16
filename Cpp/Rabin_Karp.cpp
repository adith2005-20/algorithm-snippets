#include <iostream>
#include <vector>


using namespace std;

void rabinKarp(string text, string pattern, int prime = 101) {
    int m = pattern.size(), n = text.size();
    int hashPattern = 0, hashText = 0, h = 1;
    int d = 256; // Number of characters in input alphabet

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    for (int i = 0; i < m; i++) {
        hashPattern = (d * hashPattern + pattern[i]) % prime;
        hashText = (d * hashText + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (hashPattern == hashText) {
            if (text.substr(i, m) == pattern)
                cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m) {
            hashText = (d * (hashText - text[i] * h) + text[i + m]) % prime;
            if (hashText < 0) hashText += prime;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB", pattern = "ABABCABAB";
    cout << "Rabin-Karp Algorithm:\n";
    rabinKarp(text, pattern);
    return 0;
}
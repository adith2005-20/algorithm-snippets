#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pattern) {
    int m = pattern.size(), len = 0;
    vector<int> lps(m, 0);
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

void KMP(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0, n = text.size(), m = pattern.size();
    while (i < n) {
        if (text[i] == pattern[j]) { i++; j++; }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB", pattern = "ABABCABAB";
    cout << "KMP Algorithm:\n";
    KMP(text, pattern);
    return 0;
}
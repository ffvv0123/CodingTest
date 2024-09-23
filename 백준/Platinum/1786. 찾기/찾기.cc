#include <iostream>
#include <string>
#include <vector>

using namespace std;

string T, P;

vector<int> kmp(string& s) {
    vector<int> f(s.size());
    int j = 0;

    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[j] != s[i]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }

    return f;
}

int main() {
    getline(cin, T);
    getline(cin, P);

    vector<int> f = kmp(P);
    vector<int> result;
    int j = 0;
    
    for (int i = 0; i < T.size(); i++) {
        while (j > 0 && T[i] != P[j]) j = f[j - 1];
        if (T[i] == P[j]) j++;
        if (j == P.size()) {
            result.push_back(i + 2 - P.size());
            j = f[j - 1];
        }
    }

    cout << result.size() << '\n';
    for (int x : result) cout << x << '\n';
    
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

int alphabet[26];
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(alphabet, 0, 26);
    cin >> S;

    for(int i=0; i < S.length(); i++) {
        alphabet[S[i] - 'a']++;
    }

    for(int i=0; i < 26; i++)
        cout << alphabet[i] << ' ';

    return 0;
}
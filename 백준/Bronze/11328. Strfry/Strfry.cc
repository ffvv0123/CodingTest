#include <iostream>
#include <algorithm>
using namespace std;

int N;
string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a == b) {
            cout << "Possible\n";
        }
        else cout << "Impossible\n";
    }

    return 0;
}
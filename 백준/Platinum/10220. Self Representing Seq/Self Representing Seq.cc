#include <iostream>
using namespace std;

int T, N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        if (N == 1 || N == 2 || N == 3 || N == 6) cout << 0;
        else if (N == 4) cout << 2;
        else cout << 1;

        cout << '\n';
    }

    return 0;
}
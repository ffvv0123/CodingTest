#include <iostream>
using namespace std;

int T, S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T >> S;
    if (T >= 12 && T <= 16 && S == 0) cout << 320;
    else cout << 280;

    return 0;
}
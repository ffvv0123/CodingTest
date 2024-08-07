#include <iostream>
using namespace std;

int T, C;
int q, d, n, p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> C;

        q = C / 25;
        C %= 25;

        d = C / 10;
        C %= 10;

        n = C / 5;
        C %= 5;

        p = C;

        cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
    }

    return 0;
}
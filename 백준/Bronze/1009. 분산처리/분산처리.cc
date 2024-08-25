#include <iostream>
using namespace std;

int T, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> a >> b;

        a = a % 10;

        if (a == 1 || a == 5 || a == 6) cout << a << '\n';
        else if (a == 4 || a == 9) {
            if (b % 2 == 1) cout << a << '\n';
            else cout << a * a % 10 << '\n';
        }
        else if (a == 0) cout << 10 << '\n';
        else {
            if (b % 4 == 1) cout << a << '\n';
            else if (b % 4 == 2) cout << a * a % 10 << '\n';
            else if (b % 4 == 3) cout << a * a * a % 10 << '\n';
            else cout << a * a * a * a % 10 << '\n';
        }
    }

    return 0;
}
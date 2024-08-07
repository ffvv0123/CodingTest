#include <iostream>
using namespace std;

int T;
int a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    a = T / 300;
    T %= 300;

    b = T / 60;
    T %= 60;

    c = T / 10;
    T %= 10;

    if (T != 0) {
        cout << -1;
        return 0;
    }
    
    cout << a << ' ' << b << ' ' << c;

    return 0;
}
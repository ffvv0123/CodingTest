#include <iostream>
using namespace std;

int a1, a0, c, n0;
double expr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;

    if (c <= a1 && c*n0 <= a1*n0 + a0) cout << 1;
    else cout << 0;

    return 0;
}
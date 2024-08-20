#include <iostream>
using namespace std;

int gcd(int x, int y) {
    int r;
    while(y != 0) {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a1, b1, a2, b2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    int numerator, denominator;
    numerator = a1 * b2 + a2 * b1;
    denominator = b1 * b2;

    int GCD = gcd(numerator, denominator);

    numerator /= GCD;
    denominator /= GCD;

    cout << numerator << " " << denominator;

    return 0;
}
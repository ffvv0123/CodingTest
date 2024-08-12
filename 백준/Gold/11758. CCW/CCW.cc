#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x1, y1, x2, y2, x3, y3;
    int D;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    D = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (D > 0) cout << 1;
    else if (D < 0) cout << -1;
    else cout << 0;

    return 0;
}
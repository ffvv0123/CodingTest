#include <iostream>
using namespace std;

int w, h, p, q, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> h;
    cin >> p >> q;
    cin >> t;

    if (t <= w - p) {
        cout << p + t << " ";
    }
    else {
        if (((t - w + p) / w) % 2 == 0) {
            cout << w - (t + p - w) % w << " ";
        }
        else {
            cout << (t + p - w) % w << " ";
        }
    }

    if (t <= h - q) {
            cout << q + t << "\n";
        }
    else {
        if (((t - h + q) / h) % 2 == 0) {
            cout << h - (t + q - h) % h << "\n";
        }
        else {
            cout << (t + q - h) % h << "\n";
        }
    }
    

    return 0;
}
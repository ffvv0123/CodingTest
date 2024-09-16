#include <iostream>
using namespace std;

int L, P, tmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> L >> P;

    for (int i = 0; i < 5; i++) {
        cin >> tmp;
        cout << tmp - L * P << ' ';
    }

    return 0;
}
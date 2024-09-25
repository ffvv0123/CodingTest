#include <iostream>
using namespace std;

int N, x;
int radix[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    while (N--) {
        cin >> x;
        radix[x]++;
    }

    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < radix[i]; j++) {
            cout << i << '\n';
        }
    }

    return 0;
}
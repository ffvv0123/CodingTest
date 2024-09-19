#include <iostream>
using namespace std;

int N, Pi, grundy = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Pi;
        grundy ^= Pi;
    }

    if (grundy == 0) cout << "cubelover";
    else cout << "koosaga";

    return 0;
}
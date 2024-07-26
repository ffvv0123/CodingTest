#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int cnt = 1;

    if (K == 1) {
        cout << 1;
        return 0;
    }

    for(int i = 2; i <= N; i++) {
        if(N % i == 0) {
            cnt++;
        }
        if(K == cnt) {
            cout << i;
            return 0;
        }
    }

    if (cnt < K) cout << 0;

    return 0;
}
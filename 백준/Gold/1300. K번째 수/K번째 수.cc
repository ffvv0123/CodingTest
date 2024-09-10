#include <iostream>
using namespace std;

int N, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> k;
    int low = 1, high = k;
    while (low < high) {
        int mid = (low + high) / 2, cnt = 0;

        for (int i = 1; i <= N; i++) {
            cnt += min(N, mid / i);
        }

        if (cnt < k) low = mid + 1;
        else high = mid;
    }

    cout << high;

    return 0;
}
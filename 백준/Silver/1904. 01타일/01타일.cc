#include <iostream>
#include <deque>
using namespace std;

int N;
int dp[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[1] = 1, dp[2] = 2;
    cin >> N;

    if (N > 2) {
        for(int i=3; i <= N; i++) {
            dp[i] = (dp[i-2] + dp[i-1]) % 15746;
        }
    }

    cout << dp[N];

    return 0;
}
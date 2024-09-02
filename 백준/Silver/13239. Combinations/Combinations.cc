#include <iostream>
using namespace std;

int t, n, k;
int dp[1002][1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i < 1001; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for(int i=1; i < 1001; i++) {
        for(int j = 1; j < i; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 1000000007;
        }
    }

    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << dp[n][k] << '\n';
    }

    return 0;
}
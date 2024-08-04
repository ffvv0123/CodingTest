#include <iostream>
using namespace std;

int n;
long long dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dp[0] = 1; dp[1] = 3;

    if(n > 1) {
        for(int i = 2; i < n; i++) {
            dp[i] = (2 * dp[i-2] + dp[i-1]) % 10007;
        }
    }

    cout << dp[n-1];

    return 0;
}
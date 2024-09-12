#include <iostream>
using namespace std;

int N;
int dp[10001], wine[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> wine[i];
    }
    
    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max(dp[1], wine[2] + max(wine[0], wine[1]));

    for (int i = 3; i < N; i++) {
        dp[i] = max(dp[i - 1], wine[i] + max(wine[i - 1] + dp[i - 3], dp[i - 2]));
    }

    cout << dp[N-1];
    return 0;
}
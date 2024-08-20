#include <iostream>
using namespace std;

int N, answer = 0;
int dp[41];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    
    dp[0] = 1, dp[1] = 1;
    for(int i=2; i < N; i++) {
        dp[i] = dp[i-2] + dp[i-1];
    }

    cout << dp[N-1] << " " << N - 2;

    return 0;
}
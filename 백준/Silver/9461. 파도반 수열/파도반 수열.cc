#include <iostream>
using namespace std;

long long T, N;
long long dp[101];

void find_length(int N) {
    dp[0] = 1; dp[1] = 1; dp[2] = 1; dp[3] = 2; dp[4] = 2;

    if(N > 4) {
        for(int i=5; i < N; i++) {
            dp[i] = dp[i-1] + dp[i-5];
        }
    }

    cout << dp[N-1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> N;
        find_length(N);
    }

    return 0;
}
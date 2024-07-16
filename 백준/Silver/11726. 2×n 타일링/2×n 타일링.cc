#include <iostream>
using namespace std;

int main() {
    int N;
    long long dp[1002];

    cin >> N;
    
    dp[0] = 1;
    dp[1] = 2;

    for(int i=2; i < N; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    
    cout << dp[N-1];
}
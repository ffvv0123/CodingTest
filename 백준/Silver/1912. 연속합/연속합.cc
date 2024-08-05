/**
 * dp = max(현재, 이전 + 현재)
 * dp의 최대값 -> 정답
 */
#include <iostream>
using namespace std;

int N;
int answer = 0;
int dp[100001];
int num[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> num[i];
    }

    dp[0] = num[0];
    answer = num[0];

    for(int i=1; i < N; i++) {
        dp[i] = max(dp[i-1] + num[i], num[i]);
        answer = max(answer, dp[i]);
    }
    
    cout << answer;

    return 0;
}
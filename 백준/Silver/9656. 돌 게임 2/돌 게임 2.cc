/**
 * 게임 이론 입문
 * 1 -> SK
 * 2 -> CY
 * 3 -> SK
 * 4 -> [1, 3 or 3, 1] -> CY
 * 5 -> [1, 1, 3 or 3, 1, 1 or 1, 3, 1] -> SK
 * 6 -> [3, 3 or 3, 1, 1, 1] -> CY
 * 7 -> [3, 3, 1 or ]
 * 
 * ...
 * 
 * N 턴에 3, 1을 홀수개로 사용 -> SK, 짝수개로 사용 -> CY
 * 돌: 1, 3개만 가져감. i번쨰는 i-3 + 1, i-1 + 1
 * -> 
 */
#include <iostream>
using namespace std;

int N;
bool dp[1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    // SK 승: true, CY 승: false
    dp[1] = true; dp[2] = false; dp[3] = true;
    for(int i=4; i <= N; i++) {
        dp[i] = !dp[i-1] || !dp[i-3];
    }

    if(dp[N]) cout << "CY";
    else cout << "SK";
    
    return 0;
}
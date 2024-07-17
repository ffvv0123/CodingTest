#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501];
int arr[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++)
            cin >> arr[i][j];
    }

    if (N >= 1)
        dp[0][0] = arr[0][0];

    if (N >= 2) {
        dp[1][0] = dp[0][0] + arr[1][0];
        dp[1][1] = dp[0][0] + arr[1][1];
    }

    if (N >= 3) {
        for(int i = 2; i < N; i++) {
            for(int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i-1][j] + arr[i][j];
                }
                else if(j == i){
                    dp[i][j] = dp[i-1][j-1] + arr[i][j];
                }
                else {
                    dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
                }
            }
        }
    }

    int answer = 0;

    for(int i = 0; i < N; i++) {
        if(dp[N-1][i] > answer) answer = dp[N-1][i];
    }
    
    cout << answer;

    return 0;
}
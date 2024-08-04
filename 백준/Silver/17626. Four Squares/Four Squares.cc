/**
 * 1699. 제곱수의 합 문제와 매우 유사
 */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
int dp[50001];
vector<int> square(225, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int tmp = 1;
    for(int i=0; i < n; i++) {
        dp[i] = i+1;

        if(i + 1 == tmp * tmp) {
            square[tmp - 1] = i + 1;
            dp[i] = 1;
            tmp++;
        }
    }

    for(int i=4; i < n; i++) {
        for(int j = 0; j < 255; j++) {
            if(square[j] == 0) break;
            if (square[j] <= i)
                dp[i] = min(dp[i], dp[square[j] - 1] + dp[i - square[j]]);
        }
    }

    cout << dp[n-1];  

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int n;
        int graph[2][100001] = {0}, dp[2][100001] = {0};

        cin >> n;

        for(int i = 0; i < 2; i++)
            for(int j=0; j < n; j++)
                cin >> graph[i][j];

        dp[0][0] = graph[0][0]; 
        dp[1][0] = graph[1][0];
        
        if (n > 1) {
            dp[0][1] = dp[1][0] + graph[0][1];
            dp[1][1] = dp[0][0] + graph[1][1];
        }

        if (n > 2) {
            for(int i = 2; i < n; i++) {
                dp[0][i] = graph[0][i] + max(dp[1][i-1], max(dp[0][i-2], dp[1][i-2]));
                dp[1][i] = graph[1][i] + max(dp[0][i-1], max(dp[0][i-2], dp[1][i-2]));
            }
        }             

        int answer = -1;
        for(int i=0; i < n; i++) {
            int tmp = max(dp[0][i], dp[1][i]);
            answer = max(answer, tmp);
        }
        cout << answer << '\n';
    }

    return 0;
}
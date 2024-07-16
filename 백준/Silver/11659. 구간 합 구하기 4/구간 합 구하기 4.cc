#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, a, b;
    int answer = 0;
    int list[100002];
    int dp[100002];

    cin >> N >> M;    

    for(int i=0; i<N; i++)
        cin >> list[i];

    dp[0] = list[0];    
    for(int i = 1; i < N; i++)
        dp[i] = dp[i-1] + list[i];

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        
        if (a == 0) cout << dp[b] << '\n';
        else cout << dp[b] - dp[a-1] << '\n';
    }

    return 0;
}
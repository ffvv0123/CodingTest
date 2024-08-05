/**
 * i -> j 가는 경유지가 존재하면 갈 수 있음.
 * 경유지를 k라고 할 때, i,k와 k,j가 모두 존재하면 i,j는 존재
 * -> 모든 경로에 대해 플로이드 워셜 돌리기
 */

#include <iostream>
using namespace std;

int N;
int G[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            cin >> G[i][j];
    
    for(int k = 0; k < N; k++)
        for(int i=0; i < N; i++)
            for(int j=0; j < N; j++)
                if(G[i][k] == 1 && G[k][j] == 1) G[i][j] = 1;
                
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cout << G[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

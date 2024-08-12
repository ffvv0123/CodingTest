#include <iostream>
#include <cstring>
using namespace std;

unsigned long long T, N, M;

unsigned long long bridge[31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(bridge, 0, sizeof(bridge));

    for(int i=0; i < 30; i++) {
        bridge[i][0] = 1;
        bridge[i][i] = 1;
    }
    for(int i=2; i < 30; i++) {
        for(int j = 1; j < i; j++) {
            bridge[i][j] = bridge[i-1][j] + bridge[i-1][j-1];
        }
    }

    cin >> T;
    while(T--) {
        cin >> N >> M;
        cout << bridge[M][N] << '\n';
    }

    return 0;
}
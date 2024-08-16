#include <iostream>
using namespace std;

int N;
int road[1001];
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) cin >> road[i];

    int start_pos = -1;
    int tmp = 0;
    for(int i=0; i < N; i++) {
        if(start_pos == -1) {
            start_pos = road[i];
        }
        else {
            if(road[i-1] < road[i]) {
                tmp += road[i] - road[i-1];
            }
            else {
                ans = max(ans, tmp);
                tmp = 0;
            }
        }
    }
    ans = max(ans, tmp);
    cout << ans;

    return 0;
}
#include <iostream>
using namespace std;

long long x, y, cnt = 0, sum_cnt = 0, answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;

    while(sum_cnt < x + y) {
        cnt++;
        sum_cnt += cnt;
    }

    if (sum_cnt != x + y) {
        cout << -1;
        return 0;
    }

    for(long long i=cnt; i > 0; i--) {
        if (x - i >= 0) {
            x -= i;
            answer++;
        }
        if (x == 0) break;
    }

    if (x == 0) cout << answer;
    else cout << -1;


    return 0;
}
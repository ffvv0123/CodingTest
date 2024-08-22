#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, L, x;
    deque<pair<int, int>> dq;

    cin >> N >> L;

    for(int i=0; i < N; i++) {
        cin >> x;

        while(!dq.empty() && dq.back().second >= x) {
            dq.pop_back();
        }
        dq.push_back({i, x});

        if(dq.front().first <= i - L) {
            dq.pop_front();
        }

        cout << dq.front().second << " ";
    }

    return 0;
}
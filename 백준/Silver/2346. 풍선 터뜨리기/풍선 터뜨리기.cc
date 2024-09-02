#include <iostream>
#include <deque>
using namespace std;

int N, tmp;
deque<pair<int, int>> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=1; i <= N; i++) {
        cin >> tmp;
        dq.push_back({tmp, i});
    }

    while (!dq.empty()) {
        pair<int, int> cur = dq.front();
        dq.pop_front();

        cout << cur.second << ' ';

        if (dq.empty()) break;
        if (cur.first > 0) {
            for(int i=0; i < cur.first - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for(int i=0; i < -cur.first; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}
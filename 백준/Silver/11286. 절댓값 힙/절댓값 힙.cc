#include <iostream>
#include <utility>
#include <queue>
using namespace std;

struct Compare {
    bool operator() (pair<int, int> const& a, pair<int, int> const& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        else {
            return a.second > b.second;
        }
    }
};

int N, x;
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> x;
        if(x != 0) {
            pq.push({x, abs(x)});
        }
        else {
            if(pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top().first << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}
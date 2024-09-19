#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;
int N, x, y;

vector<pair<ll, ll>> v;
stack<pair<ll, ll>> s;

int CCW(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C) {
    long tmp = A.first * B.second + B.first * C.second + C.first * A.second;
	tmp -= B.first * A.second + C.first * B.second + A.first * C.second;

    if (tmp > 0) return 1;
    else if (tmp < 0) return -1;
    else return 0;
}

bool compare(pair<ll, ll> A, pair<ll, ll> B) {
    int ccw = CCW(v[0], A, B);

    if (ccw == 0) {
        return (A.first - v[0].first) * (A.first - v[0].first) + 
               (A.second - v[0].second) * (A.second - v[0].second) <
               (B.first - v[0].first) * (B.first - v[0].first) + 
               (B.second - v[0].second) * (B.second - v[0].second);
    }
    return ccw > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back({ x, y });
    }

    sort(v.begin(), v.end());
    sort(v.begin() + 1, v.end(), compare);

    s.push(v[0]);
    s.push(v[1]);

    for (int i = 2; i < N; i++) {
        while (s.size() >= 2) {
            pair<ll, ll> second = s.top();
            s.pop();
            pair<ll, ll> first = s.top();

            if (CCW(first, second, v[i]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(v[i]);
    }

    cout << s.size();

    return 0;
}
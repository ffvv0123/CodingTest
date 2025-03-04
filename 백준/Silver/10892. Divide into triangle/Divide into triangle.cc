#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N, x, y;
pair<int, pair<int, int>> stick[901];

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.second != b.second.second) {
        return a.second.second < b.second.second;
    }
    return a.second.first < b.second.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= 3 * N; i++) {
        cin >> x >> y;
        stick[i - 1].first = i;
        stick[i - 1].second.first = x;
        stick[i - 1].second.second = y;
    }

    sort(stick, stick + 3 * N, compare);

    for (int i = 0; i < 3 * N; i++) {
        if (i > 0 && i % 3 == 0) cout << '\n';
        cout << stick[i].first << ' ';
    }

    return 0;
}
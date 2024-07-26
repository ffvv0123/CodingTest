#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int N, b, p, q, r;
vector<pair<int, pair<int, int>>> players;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if(a.second.first == b.second.first && a.second.second == b.second.second) {
        return a.first < b.first;
    }
    else if(a.second.first == b.second.first) {
        return a.second.second < b.second.second;
    }
    return a.second.first < b.second.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> b >> p >> q >> r;
        players.push_back({b, {p * q * r, p + q + r}});
    }

    sort(players.begin(), players.end(), compare);

    for(int i=0; i < 3; i++) {
        cout << players[i].first << " ";
    }

    return 0;
}
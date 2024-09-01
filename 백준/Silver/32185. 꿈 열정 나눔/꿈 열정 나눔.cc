#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, v, p, s;
int standard, tmp_s;
vector<pair<int, int>> score_list;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    cin >> v >> p >> s;
    
    standard = v + p + s;

    for(int i=1; i <= N; i++) {
        tmp_s = 0;
        cin >> v >> p >> s;
        tmp_s = v + p + s;

        if (tmp_s > standard) continue;
        score_list.push_back({tmp_s, i});
    }

    sort(score_list.rbegin(), score_list.rend());
    score_list.insert(score_list.begin(), {standard, 0});

    if (score_list.size() <= M) {
        for(int i=0; i < score_list.size(); i++) {
            cout << score_list[i].second << ' ';
        }
    }
    else {
        for(int i=0; i < M; i++) {
            cout << score_list[i].second << ' ';
        }
    }

    return 0;
}
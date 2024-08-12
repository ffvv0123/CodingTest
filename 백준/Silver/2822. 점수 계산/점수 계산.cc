#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0;
pair<int, int> score[8];
int idx[5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i < 8; i++) {
        cin >> score[i].first;
        score[i].second = i;
    }

    sort(score, score + 8, greater<pair<int, int>>());
    for(int i=0; i < 5; i++) {
        answer += score[i].first;
        idx[i] = score[i].second;
    }

    sort(idx, idx + 5);

    cout << answer << '\n';
    for(auto i : idx) cout << i+1 << ' ';

    return 0;
}
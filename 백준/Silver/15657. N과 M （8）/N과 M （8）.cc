#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, x;
vector<int> seq, answer;

void dfs() {
    if (answer.size() == M) {
        for (int num : answer) cout << num << " ";
        cout << '\n';
        return;
    }

    for(int i=0; i < N; i++) {
        if (answer.empty() || answer.back() <= seq[i]) {
            answer.push_back(seq[i]);
            dfs();
            answer.pop_back();
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i < N; i++) {
        cin >> x;
        seq.push_back(x);
    }
    sort(seq.begin(), seq.end());

    dfs();

    return 0;
}
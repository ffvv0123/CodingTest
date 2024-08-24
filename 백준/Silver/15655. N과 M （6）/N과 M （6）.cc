#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, x;
vector<int> seq, answer;
bool check[8];

void dfs() {
    if (answer.size() == M) {
        for (int num : answer) cout << num << " ";
        cout << '\n';
        return;
    }

    for(int i=0; i < N; i++) {
        if (!check[i] && (answer.empty() || answer.back() < seq[i])) {
            check[i] = true;
            answer.push_back(seq[i]);
            dfs();
            answer.pop_back();
            check[i] = false;
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
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> answer;

void dfs(vector<int> &answer) {
    if (answer.size() == M) {
        for (int num : answer)
            cout << num << " ";
        cout << "\n";
        return;
    }

    for(int i = 1; i < N+1; i++) {
        answer.push_back(i);
        dfs(answer);
        answer.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    dfs(answer);

    return 0;
}
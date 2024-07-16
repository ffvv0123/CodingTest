#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> answer;

void dfs(vector<int> &answer, int start) {
    
    if (answer.size() == M) {
        for (int num : answer)
            cout << num << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i < N+1; i++) {
        answer.push_back(i);
        dfs(answer, i+1);
        answer.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    dfs(answer, 1);

    return 0;
}
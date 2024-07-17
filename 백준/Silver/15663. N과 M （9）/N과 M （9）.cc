#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> answer, input;
bool check[10];

void dfs(int depth) {
    if (depth == M) {
        for(int num : answer)
            cout << num << " ";
        cout << '\n';
        return;
    }

    int last = -1;
    for(int i = 0; i < N; i++) {
        if (!check[i] && input[i] != last) {
            check[i] = true;
            answer.push_back(input[i]);
            last = input[i];
            dfs(depth + 1);
            answer.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    input.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> input[i];
    }

    sort(input.begin(), input.end());
    dfs(0);

    return 0;
}

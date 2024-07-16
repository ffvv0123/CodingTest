#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, tmp;
vector<int> answer;
vector<int> input;

void dfs(vector<int> &answer, vector<int> &input) {
    if (answer.size() == M) {
        for(int num : answer)
            cout << num << " ";
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if (find(answer.begin(), answer.end(), input[i]) == answer.end()) {
            answer.push_back(input[i]);
            dfs(answer, input);
            answer.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    input.resize(N);
    
    for(int i=0; i < N; i++)
        cin >> input[i];

    sort(input.begin(), input.end());
    dfs(answer, input);

    return 0;
}
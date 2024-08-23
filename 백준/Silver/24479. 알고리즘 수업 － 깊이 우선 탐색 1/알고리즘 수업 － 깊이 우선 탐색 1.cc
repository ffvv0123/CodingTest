#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R, src, dst;
int order = 1;
vector<int> node[100002];
int visited[100002];

void dfs(int start) {
    if(visited[start]) return;

    visited[start] = order++;

    sort(node[start].begin(), node[start].end());
    for(int i=0; i < node[start].size(); i++) {
        dfs(node[start][i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> R;
    for(int i=0; i < M; i++) {
        cin >> src >> dst;
        node[src].push_back(dst);
        node[dst].push_back(src);
    }

    dfs(R);

    for(int i=1; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}
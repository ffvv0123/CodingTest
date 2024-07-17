#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
using namespace std;

int N, x, y;
vector<int> graph[100001];
int visited[100001];

void bfs(int start_node) {
    deque<int> dq;
    dq.push_back(start_node);
    visited[start_node] = 0;

    while (!dq.empty()) {
        int current_node = dq.front();
        dq.pop_front();

        for (int next_node : graph[current_node]) {
            if (visited[next_node] == -1) {
                visited[next_node] = current_node;
                dq.push_back(next_node);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    memset(visited, -1, sizeof(visited));

    for(int i=0; i < N-1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bfs(1);

    for(int i=2; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}
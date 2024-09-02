#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, K, answer = 0;
int visited[200004];

void bfs(int N) {
    queue<int> q;
    q.push(N);
    visited[N] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) {
            cout << visited[cur];
            break;
        }

        if (2 * cur <= 200000 && visited[2 * cur] == -1) {
            q.push(2 * cur);
            visited[2 * cur] = visited[cur];
        }
        if (cur - 1 >= 0 && visited[cur - 1] == -1) {
            q.push(cur - 1);
            visited[cur - 1] = visited[cur] + 1;
        }
        if (cur + 1 <= 200000 && visited[cur + 1] == -1) {
            q.push(cur + 1);
            visited[cur + 1] = visited[cur] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    memset(visited, -1, sizeof(visited));

    bfs(N);

    return 0;
}
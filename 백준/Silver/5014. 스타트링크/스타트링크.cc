#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int F, S, G;
int dx[2]; // 층수, 목적지, 출발점, 올라가는 수, 내려가는 수
int answer = 0;
int visited[1000002];

void bfs() {
    queue<int> q;
    q.push(S);
    visited[S] = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i=0; i < 2; i++) {
            int nx = x + dx[i];

            if (nx < 1 || nx > F) continue;
            if (visited[nx] != -1) continue;

            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
    }
    if (visited[G] == -1) cout << "use the stairs";
    else cout << visited[G];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(visited, -1, sizeof(visited));

    cin >> F >> S >> G >> dx[0] >> dx[1];
    dx[1] *= -1;
    bfs();

    return 0;
}
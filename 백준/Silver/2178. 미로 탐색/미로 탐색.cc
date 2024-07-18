#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int graph[101][101];
int N, M;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int start_x, int start_y) {
    deque<pair<int, int>> dq;
    dq.push_back({start_x, start_y});

    while(!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for(int i=0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if(graph[nx][ny] != 1)
                continue;
            
            dq.push_back({nx, ny});
            graph[nx][ny] = graph[x][y] + 1;
        }
    }
    return graph[N-1][M-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j < M; j++)
            graph[i][j] = tmp[j] == '0' ? 0 : 1;
    }

    cout << bfs(0, 0);

    return 0;
}
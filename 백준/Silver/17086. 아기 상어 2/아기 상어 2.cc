#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int N, M, answer = 0;
int board[51][51];
bool visited[51][51];

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int bfs(int start_x, int start_y) {
    deque<pair<pair<int, int>, int>> dq;
    dq.push_back({{start_x, start_y}, 0});
    visited[start_x][start_y] = true;

    while(!dq.empty()) {
        int x = dq.front().first.first;
        int y = dq.front().first.second;
        int dist = dq.front().second;
        dq.pop_front();

        if (board[x][y] == 1) {
            return dist;
        }

        for(int i=0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > N || ny < 0 || ny > M) continue;
            if (visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            dq.push_back({{nx, ny}, dist + 1});            
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 0) {
                memset(visited, false, sizeof(visited));
                answer = max(answer, bfs(i, j));
            }
        }
    }

    cout << answer;

    return 0;
}
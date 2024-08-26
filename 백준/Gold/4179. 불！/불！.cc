#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
char graph[1002][1002];
int fire_map[1002][1002];
int visited[1002][1002];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> q1, q2;

void bfs_fire() {
    while(!q1.empty()) {
        int x = q1.front().first;
        int y = q1.front().second;
        q1.pop();

        for(int i=0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (fire_map[nx][ny] >= 0 || graph[nx][ny] == '#') continue;

            fire_map[nx][ny] = fire_map[x][y] + 1;
            q1.push({nx, ny});
        }
    }
}

void escape() {
    while(!q2.empty()) {
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();

        for(int i=0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];


            if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                cout << visited[x][y] + 1;
                return;
            }

            if (visited[nx][ny] >= 0 || graph[nx][ny] == '#') continue;
            if (fire_map[nx][ny] >= 0 && visited[x][y] + 1 >= fire_map[nx][ny]) continue;

            visited[nx][ny] = visited[x][y] + 1;
            q2.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pair<int, int> init_pos, fire_pos;

    memset(fire_map, -1, sizeof(fire_map));
    memset(visited, -1, sizeof(visited));

    cin >> R >> C;
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 'F') {
                q1.push({i, j});
                fire_map[i][j] = 0;
            }
            if (graph[i][j] == 'J') {
                q2.push({i, j});
                visited[i][j] = 0;
            }
        }
    }

    bfs_fire();
    escape();
    
    return 0;
}
#include <iostream>
#include <cstring>
#include <deque>
#include <tuple>
using namespace std;

int L, R, C;
string column;

char building[31][31][31];
bool visited[31][31][31];
int dist[31][31][31];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int solution(int start_x, int start_y, int start_z) {
    deque<pair<int, pair<int, int>>> dq;
    visited[start_x][start_y][start_z] = true;
    dq.push_back({start_x, {start_y, start_z}});

    while(!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second.first;
        int z = dq.front().second.second;
        dq.pop_front();

        for(int i=0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= L || ny >= R || nz >= C) continue;
            if (visited[nx][ny][nz] || building[nx][ny][nz] == '#') continue;

            dq.push_back({nx, {ny, nz}});
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            visited[nx][ny][nz] = true;

            if (building[nx][ny][nz] == 'E') {
                return dist[nx][ny][nz];
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true) {
        memset(building, 0, sizeof(building));
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));

        cin >> L >> R >> C;
        if (L == 0 || R == 0 || C == 0) break;

        int start_x, start_y, start_z;
        for(int i=0; i < L; i++) {
            for(int j=0; j < R; j++) {
                cin >> column;
                for(int k=0; k < C; k++) {
                    building[i][j][k] = column[k];
                    if (building[i][j][k] == 'S') {
                        tie(start_x, start_y, start_z) = {i, j, k};
                    }
                }
            }
        }

        int answer = solution(start_x, start_y, start_z);

        if (answer > 0) cout << "Escaped in " << answer << " minute(s).\n";
        else cout << "Trapped!\n";
    }

    return 0;
}
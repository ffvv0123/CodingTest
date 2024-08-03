#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int M, N, H;
int answer = 0;
int box[101][101][101];
int date[101][101][101];
bool visited[101][101][101];
bool is_possible = true;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct component {
    int z, y, x;
};

void bfs() {
    deque<component> dq;

    for(int i=0; i < H; i++) {
        for(int j=0; j < N; j++) {
            for(int k=0; k < M; k++) {
                if(box[i][j][k] == 1) {
                    dq.push_back({i, j, k});
                    visited[i][j][k] = true;
                }
            }
        }
    }

    while(!dq.empty()) {
        int x = dq.front().x;
        int y = dq.front().y;
        int z = dq.front().z;

        dq.pop_front();

        for(int i=0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
            if (visited[nz][ny][nx]) continue;
            if (box[nz][ny][nx] == -1) continue;

            visited[nz][ny][nx] = true;
            if(box[nz][ny][nx] == 0) {
                box[nz][ny][nx] = 1;
                dq.push_back({nz, ny, nx});
                date[nz][ny][nx] = date[z][y][x] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> H;

    for(int i=0; i < H; i++)
        for(int j=0; j < N; j++)
            for(int k=0; k < M; k++)
                cin >> box[i][j][k];

    memset(date, 0, sizeof(date));
    
    bfs();

    for(int i=0; i < H; i++) {
        for(int j=0; j < N; j++) {
            for(int k=0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    is_possible = false;
                }
                answer = max(answer, date[i][j][k]);
            }
        }
    }

    if (is_possible) cout << answer;
    else cout << -1;

    return 0;
}
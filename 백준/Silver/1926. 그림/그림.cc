#include <iostream>
#include <queue>
using namespace std;

int n, m;
int num_pictures = 0, max_area = 0;
int picture[501][501];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> q;

void bfs(int start_x, int start_y) {
    int area = 1;
    num_pictures++;

    q.push({start_x, start_y});
    picture[start_x][start_y] = 0;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (picture[nx][ny] == 0) continue;

            picture[nx][ny] = 0;
            area++;

            q.push({nx, ny});
        }
    }
    max_area = max(max_area, area);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> picture[i][j];
    
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if (picture[i][j] == 1) {
                bfs(i, j);
            }
        }
    }
            
    cout << num_pictures << '\n';
    cout << max_area;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n, m;
int start_x, start_y;
int graph[1001][1001];
int answer[1001][1001];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
    deque<pair<int, int>> q;
    q.push_back({start_x, start_y});

    answer[start_x][start_y] = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();

        for(int i=0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (answer[nx][ny] == -1 && graph[nx][ny] == 1) {
                    answer[nx][ny] = answer[x][y] + 1;
                    q.push_back({nx, ny});
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (graph[i][j] == 0) {
                answer[i][j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 2) {
                start_x = i; start_y = j;
            }
            answer[i][j] = -1;
        }

    bfs();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            cout << answer[i][j] << ' ';
        cout << '\n';
    }
}
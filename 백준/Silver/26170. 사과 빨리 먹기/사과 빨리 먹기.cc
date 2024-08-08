#include <iostream>
#include <utility>
using namespace std;

int r, c;
int answer = 10000000;
int graph[5][5];
bool visited[5][5];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int step = 0, int apple = 0) {
    if (apple == 3) {
        answer = min(answer, step);
    }

    for(int i=0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[nx][ny]) continue;

        visited[nx][ny] = true;
        dfs(nx, ny, step + 1, apple + graph[nx][ny]);
        visited[nx][ny] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i < 5; i++)
        for(int j=0; j < 5; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1)
                visited[i][j] = true;
        }
    
    cin >> r >> c;
    visited[r][c] = true;

    dfs(r, c);
    
    if(answer == 10000000) answer = -1;
    cout << answer;
    
    return 0;
}
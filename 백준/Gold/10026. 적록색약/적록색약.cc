#include <iostream>
#include <deque>
#include <utility>
#include <cstring>
using namespace std;

int N;
char graph[101][101];
bool visited[101][101];
int normal_answer = 0, error_answer = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int start_x, int start_y) {
    deque<pair<int, int>> dq;
    dq.push_back({start_x, start_y});
    visited[start_x][start_y] = true;

    char color = graph[start_x][start_y];

    while(!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for(int i=0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(visited[nx][ny]) continue;
            if(graph[nx][ny] == color) {
                visited[nx][ny] = true;
                dq.push_back({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0; i < N; i++) {
        string tmp;
        cin >> tmp;

        for(int j=0; j < N; j++) {
            graph[i][j] = tmp[j];
        }
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
                normal_answer++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if(graph[i][j] == 'G') graph[i][j] = 'R';
        }
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
                error_answer++;
            }
        }
    }

    cout << normal_answer << ' ' << error_answer;
    return 0;   
}
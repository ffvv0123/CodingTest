#include <iostream>
#include <utility>
#include <deque>
#include <cstring>
using namespace std;

int N, M;
int answer = 0;
char graph[601][601];
bool visited[601][601];
pair<int, int> start_pos;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int start_x, int start_y) {
    deque<pair<int, int>> dq;
    dq.push_back({start_x, start_y});
    visited[start_x][start_y] = true;

    while(!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for(int i=0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nx][ny]) continue;
            if (graph[nx][ny] == 'P') {
                answer++;
                dq.push_back({nx, ny});
                visited[nx][ny] = true;
            }
            else if (graph[nx][ny] == 'O') {
                dq.push_back({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    memset(visited, false, sizeof(visited));

    for(int i=0; i < N; i++) {
        string tmp;
        cin >> tmp;

        for(int j=0; j < M; j++) {
            graph[i][j] = tmp[j];

            if (graph[i][j] == 'I') {
                start_pos.first = i;
                start_pos.second = j;
            }
        }
    }

    bfs(start_pos.first, start_pos.second);
    
    if(answer == 0) cout << "TT";
    else cout << answer;

    return 0;
}
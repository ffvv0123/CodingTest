#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int graph[101][101];
bool visited[101][101];
vector<int> answer;
int N;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int start_x, int start_y, int number) {
    deque<pair<int, int>> dq;
    dq.push_back({start_x, start_y});
    visited[start_x][start_y] = true;
    int checker = 1;

    while(!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for(int i=0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if(graph[nx][ny] != 1)
                continue;
            if(visited[nx][ny])
                continue;
            
            dq.push_back({nx, ny});
            graph[nx][ny] = number;
            visited[nx][ny] = true;
            checker++;
        }
    }
    return checker;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j < N; j++)
            graph[i][j] = tmp[j] == '0' ? 0 : 1;
    }

    answer.resize(0);

    int number = 1;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if (visited[i][j] == false && graph[i][j] != 0) {
                answer.push_back(bfs(i, j, number));
                number++;
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for(int i : answer) cout << i << '\n';

    return 0;
}
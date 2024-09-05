#include <iostream>
#include <cstring>
using namespace std;

int visited[3000][3000];
pair<int, int> pos = {1200, 1200};
int N, S, answer = 200000, timer = 0;
char C;

void grow(int n) {
    for(int i=0; i < 3000; i++) {
        for(int j=0; j < 3000; j++) {
            if (visited[i][j] <= n) visited[i][j] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(visited, -1, sizeof(visited));
    visited[pos.first][pos.second] = timer;

    for(int i=0; i < N; i++) {
        cin >> C >> S;
        for(int t = 0; t < S; t++) {
            timer++;
            if (C == 'N') {
                pos.second++;
                if (visited[pos.first][pos.second] != -1) {
                    answer = min(answer, timer - visited[pos.first][pos.second]);
                    grow(answer);
                }
                visited[pos.first][pos.second] = timer;
            }
            else if (C == 'S') {
                pos.second--;
                if (visited[pos.first][pos.second] != -1) {
                    answer = min(answer, timer - visited[pos.first][pos.second]);
                    grow(answer);
                }
                visited[pos.first][pos.second] = timer;
            }
            else if (C == 'W') {
                pos.first--;
                if (visited[pos.first][pos.second] != -1) {
                    answer = min(answer, timer - visited[pos.first][pos.second]);
                    grow(answer);
                }
                visited[pos.first][pos.second] = timer;
            }
            else if (C == 'E') {
                pos.first++;
                if (visited[pos.first][pos.second] != -1) {
                    answer = min(answer, timer - visited[pos.first][pos.second]);
                    grow(answer);
                }
                visited[pos.first][pos.second] = timer;
            }
        }
    }

    if (answer == 200000) cout << -1;
    else cout << answer;
    return 0;
}
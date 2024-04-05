#include <iostream>
#include <queue>
using namespace std;

int box[1002][1002];
int visited[1002][1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void ans(){
    int N, M;
    cin >> M >> N;

    queue<pair<int, int> > q;

    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            cin >> box[i][j];
            visited[i][j] = -1;

            if(box[i][j] == 1){
                q.push(make_pair(i, j));
                visited[i][j]++;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(new_x >= 0 && new_y >= 0 && N > new_x && M > new_y
            && visited[new_x][new_y] == -1 && box[new_x][new_y] == 0
            ) {
                q.push(make_pair(new_x, new_y));
                visited[new_x][new_y] = visited[x][y] + 1;
            }
        }
    }

    int answer = -1;
    bool flag = false;

    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++) {
            if(answer <= visited[i][j]) {
                answer = visited[i][j];
            }
            if(box[i][j] == 0 && visited[i][j] == -1) {
                answer = -1;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    cout << answer;
}

int main() {
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    ans();

    return 0;
}
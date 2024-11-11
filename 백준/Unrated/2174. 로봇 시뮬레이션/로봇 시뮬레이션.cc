#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int posX[101];
int posY[101];
int dirNum[101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A, B, N, M;
    cin >> A >> B >> N >> M;
    vector<vector<int>> grid(A + 1, vector<int>(B + 1, 0));

    // 방향 매핑: 'N'->0, 'E'->1, 'S'->2, 'W'->3
    int dir_map[256];
    memset(dir_map, -1, sizeof(dir_map));
    dir_map['N'] = 0;
    dir_map['E'] = 1;
    dir_map['S'] = 2;
    dir_map['W'] = 3;

    for(int r = 1; r <= N; r++) {
        char d;
        cin >> posX[r] >> posY[r] >> d;
        dirNum[r] = dir_map[d];
        grid[posX[r]][posY[r]] = r;
    }

    string message = "OK";
    bool crashed = false;
    for(int m = 0; m < M; m++) {
        int robot, repeat;
        char action;
        cin >> robot >> action >> repeat;
        if(!crashed) {
            if(action == 'L' || action == 'R') {
                repeat %= 4;
                if(action == 'L') {
                    dirNum[robot] = (dirNum[robot] + 4 - repeat) % 4;
                }
                else {
                    dirNum[robot] = (dirNum[robot] + repeat) % 4;
                }
            }
            else if(action == 'F') {
                for(int rep = 0; rep < repeat; rep++) {
                    int current_x = posX[robot];
                    int current_y = posY[robot];
                    int new_x = current_x + dx[dirNum[robot]];
                    int new_y = current_y + dy[dirNum[robot]];
                    if(new_x <= 0 || new_x > A || new_y <= 0 || new_y > B) {
                        message = "Robot " + to_string(robot) + " crashes into the wall";
                        crashed = true;
                        for(int rem = m + 1; rem < M; rem++) {
                            int temp_robot, temp_repeat;
                            char temp_action;
                            cin >> temp_robot >> temp_action >> temp_repeat;
                        }
                        break;
                    }
                    if(grid[new_x][new_y] != 0) {
                        message = "Robot " + to_string(robot) + " crashes into robot " + to_string(grid[new_x][new_y]);
                        crashed = true;
                        for(int rem = m + 1; rem < M; rem++) {
                            int temp_robot, temp_repeat;
                            char temp_action;
                            cin >> temp_robot >> temp_action >> temp_repeat;
                        }
                        break;
                    }
                    grid[current_x][current_y] = 0;
                    grid[new_x][new_y] = robot;
                    posX[robot] = new_x;
                    posY[robot] = new_y;
                }
            }
        }
    }
    cout << message << "\n";

    return 0;
}

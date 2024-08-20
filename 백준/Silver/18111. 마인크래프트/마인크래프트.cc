#include <iostream>
using namespace std;

int N, M, B;
int ans_time = 100000000, ans_height = 100000000;
int world[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int max_height = -1, min_height = 257;

    cin >> N >> M >> B;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> world[i][j];

            if(world[i][j] > max_height) max_height = world[i][j];
            if(world[i][j] < min_height) min_height = world[i][j];
        }
    }

    for(int h = min_height; h <= max_height; h++) {
        int remove = 0, add = 0, tmp;

        for(int i=0; i < N; i++) {
            for(int j=0; j < M; j++) {
                if (world[i][j] > h) {
                    remove += world[i][j] - h;
                }
                else {
                    add += h - world[i][j];
                }
            }
        }

        if (add <= remove + B) {
            tmp = 2*remove + add;
            if(ans_time > tmp) {
                ans_time = tmp;
                ans_height = h;
            }
            else if (ans_time == tmp) {
                ans_height = h;
            }
        }
    }

    cout << ans_time << " " << ans_height;

    return 0;
}
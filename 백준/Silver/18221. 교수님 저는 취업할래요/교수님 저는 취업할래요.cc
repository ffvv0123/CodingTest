#include <iostream>
#include <utility>
using namespace std;

int dist(int a, int b, int c, int d) {
    return (a-c) * (a-c) + (b-d) * (b-d);
}

int N, idx1, idx2;
int classroom[1001][1001];
bool is_slave = false;
pair<int, int> sk, prof;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> classroom[i][j];

            if (classroom[i][j] == 0 || classroom[i][j] == 1) continue;
            else if (classroom[i][j] == 5) prof = {i, j};
            else if (classroom[i][j] == 2) sk = {i, j};
        }
    }

    if (prof.first == sk.first) {
        idx1 = max(prof.second, sk.second);
        idx2 = min(prof.second, sk.second);
        if (idx1 - idx2 < 5) is_slave = true;

        int cnt_student = 0;
        for(int i=idx2+1; i < idx1; i++) {
            if (classroom[prof.first][i] == 1) cnt_student++;
        }
        if (cnt_student < 3) is_slave = true;
    }
    else if (prof.second == sk.second) {
        idx1 = max(prof.first, sk.first);
        idx2 = min(prof.first, sk.first);
        if (idx1 - idx2 < 5) is_slave = true;

        int cnt_student = 0;
        for(int i=idx2+1; i < idx1; i++) {
            if (classroom[i][prof.second] == 1) cnt_student++;
        }
        if (cnt_student < 3) is_slave = true;
    }
    else {
        if(dist(prof.first, prof.second, sk.first, sk.second) < 25) is_slave = true;

        int x_min = min(prof.first, sk.first);
        int x_max = max(prof.first, sk.first);
        int y_min = min(prof.second, sk.second);
        int y_max = max(prof.second, sk.second);

        int cnt_student = 0;
        for(int x = x_min; x <= x_max; x++)
            for (int y = y_min; y <= y_max; y++)
                if (classroom[x][y] == 1) cnt_student++;
        if (cnt_student < 3) is_slave = true;
    }

    if(is_slave) cout << 0;
    else cout << 1;

    return 0;
}
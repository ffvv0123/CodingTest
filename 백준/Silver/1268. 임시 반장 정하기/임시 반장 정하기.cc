#include <iostream>
using namespace std;

int N, answer;
int classmate[1001][5];
bool is_classmate[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> classmate[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            for (int k = 0; k < 5; k++) {
                if (classmate[i][k] == classmate[j][k]) {
                    is_classmate[i][j] = true;
                }
            }
        }
    }

    int tmp_cnt = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (is_classmate[i][j]) cnt++;
        }
        if (cnt > tmp_cnt) {
            answer = i + 1;
            tmp_cnt = cnt;
        }
    }

    if (answer == 0) answer = 1;
    cout << answer;

    return 0;
}
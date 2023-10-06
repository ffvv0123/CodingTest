#include <iostream>
#include <vector>
using namespace std;

// void ans() {
//     int N, H;
//     cin >> N >> H;

//     vector<int> block(N);
//     vector<vector<int> > map(H, vector<int>(N));

//     for (int i = 0; i < N; i++){
//         cin >> block[i];
//     }

//     for (int i = 0; i < H; i++) {
//         for (int j = 0; j < N; j++) {
//             map[i][j] = 0;
//         }
//     }

//     for (int i = 0; i < N; i++) {
//         if (i % 2 == 0) {
//             for (int j = H - 1; j >= H - block[i]; j--) {
//                 map[j][i] = 1;
//             }
//         }
//         else if (i % 2 == 1) {
//             for (int j = 0; j < block[i]; j++) {
//                 map[j][i] = 1;
//             }
//         }
//     }

//     int cnt = 0;
//     int min_val = N;

//     for (int i = 0; i < H; i++) {
//         int tmp = 0;
//         for (int j = 0; j < N; j++) {
//             if (map[i][j] == 1) {
//                 tmp++;
//             }
//         }
//         if (min_val > tmp) {
//             min_val = tmp;
//             cnt = 1;
//         }
//         else if (min_val == tmp) {
//             cnt++;
//         }
//     }
//     cout << min_val << " " << cnt;

// }

void ans() {
    int N, H;
    cin >> N >> H;
    vector<int> bot(H + 1, 0);
    vector<int> top(H + 1, 0);
    vector<int> result(H + 1, 0);

    for (int i = 0; i < N / 2; i++) {
        int bot_pos, top_pos;
        cin >> bot_pos >> top_pos;
        bot[bot_pos]++;
        top[H + 1 - top_pos]++;
    }

    for (int i = H - 1; i >= 1; i--) {
        bot[i] += bot[i + 1];
    }

    int min_val = 1000000;
    int cnt = 0;

    for (int i = 1; i <= H; i++) {
        top[i] += top[i - 1];
        result[i] += bot[i] + top[i];
        if (min_val > result[i]) {
            cnt = 1;
            min_val = result[i];
        }
        else if (result[i] == min_val) {
            cnt++;
        }
    }

    cout << min_val << " " << cnt;
}

int main() {
    ans();

    return 0;
}

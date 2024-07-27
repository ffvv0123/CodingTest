#include <iostream>
using namespace std;

int N, x1, x2, x3, i;
int max_score = 0, min_score = 0;
int max_tmp[2][3], min_tmp[2][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> x1 >> x2 >> x3;

    max_tmp[0][0] = x1; min_tmp[0][0] = x1;
    max_tmp[0][1] = x2; min_tmp[0][1] = x2;
    max_tmp[0][2] = x3; min_tmp[0][2] = x3;

    for(i=1; i < N; i++) {
        cin >> x1 >> x2 >> x3;
        max_tmp[1][0] = x1 + max(max_tmp[0][0], max_tmp[0][1]);
        max_tmp[1][1] = x2 + max(max_tmp[0][0], max(max_tmp[0][1], max_tmp[0][2]));
        max_tmp[1][2] = x3 + max(max_tmp[0][1], max_tmp[0][2]);

        min_tmp[1][0] = x1 + min(min_tmp[0][0], min_tmp[0][1]);
        min_tmp[1][1] = x2 + min(min_tmp[0][0], min(min_tmp[0][1], min_tmp[0][2]));
        min_tmp[1][2] = x3 + min(min_tmp[0][1], min_tmp[0][2]);

        for(int i=0; i < 3; i++) {
            max_tmp[0][i] = max_tmp[1][i];
            min_tmp[0][i] = min_tmp[1][i];
        }
    }

    cout << max(max_tmp[0][0], max(max_tmp[0][1], max_tmp[0][2])) << ' ';
    cout << min(min_tmp[0][0], min(min_tmp[0][1], min_tmp[0][2]));
}
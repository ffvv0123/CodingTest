#include <iostream>
using namespace std;

int N, tmp, answer = -1;
int state[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        state[tmp]++;
    }

    for (int i = 0; i < 51; i++) {
        if (state[i] == i) answer = i;
    }

    cout << answer;

    return 0;
}
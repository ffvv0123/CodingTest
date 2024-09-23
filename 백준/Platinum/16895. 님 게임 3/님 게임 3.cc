#include <iostream>
using namespace std;

int N, grundy, answer = 0;
int P[1001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++) {
        grundy = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            grundy ^= P[j];
        }
        for (int j = 0; j < P[i]; j++) {
            if ((grundy ^ j) == 0) answer++;
        }
    }

    cout << answer;

    return 0;
}
#include <iostream>
using namespace std;

int N, M;
int A[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];

    int tmp, answer = 0;
    for (int i = 0; i < N; i++) {
        tmp = 0;
        for (int j = i; j < N; j++) {
            if (tmp < M) {
                tmp += A[j];
            }
            else if (tmp == M) {
                answer++;
                tmp = 0;
                break;
            }
            else {
                tmp = 0;
                break;
            }
        }
        if (tmp == M) answer++;
    }

    cout << answer;

    return 0;
}
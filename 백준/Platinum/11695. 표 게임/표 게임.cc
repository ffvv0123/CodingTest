#include <iostream>
using namespace std;

long long  N, M, tmp, answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        long long grundy = 0;
        for (int j = 0; j < M; j++) {
            cin >> tmp;
            grundy += tmp;
        }
        answer ^= grundy;
    }

    answer == 0 ? cout << "ainta" : cout << "august14";

    return 0;
}
#include <iostream>
using namespace std;

int N, M, tmp;
long long remain[1001];

long long nC2(long long num) {
    return num * (num - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    long long p_sum = 0;
    for(int i=0; i < N; i++) {
        cin >> tmp;
        p_sum += tmp;
        remain[p_sum % M]++;
    }

    long long answer = remain[0];

    for(int i=0; i < M; i++) {
        answer += nC2(remain[i]);
    }

    cout << answer;

    return 0;
}
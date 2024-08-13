#include <iostream>
using namespace std;

int N, M, answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    if(N == 1) {
        answer = 1;
    }
    else if (N == 2) {
        answer = min(4, (M + 1)/ 2);
    }
    else if (M < 7) {
        answer = min(4, M);
    }
    else {
        answer = M - 2;
    }

    cout << answer;

    return 0;
}
#include <iostream>
using namespace std;

int N, C, K;
int answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    while (N--) {
        cin >> C >> K;
        answer += C * K;
    }

    cout << answer;
    return 0;
}
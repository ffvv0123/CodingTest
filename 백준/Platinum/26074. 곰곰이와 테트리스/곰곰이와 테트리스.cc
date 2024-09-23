#include <iostream>
using namespace std;

int N, M, tmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < 8; i++) cin >> tmp;

    N * M == 2 ? cout << "ChongChong" : cout << "GomGom";

    return 0;
}
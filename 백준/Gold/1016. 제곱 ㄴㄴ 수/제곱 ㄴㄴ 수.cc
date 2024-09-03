#include <iostream>
using namespace std;

long long min_v, max_v, answer = 0;
bool is_square[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> min_v >> max_v;

    for(long long i = 2; i*i <= max_v; i++) {
        long long ret = min_v / (i * i);
        if (min_v % (i * i) != 0) ret++;

        while(ret * (i * i) <= max_v) {
            if (!is_square[ret * (i * i) - min_v]) {
                is_square[ret * (i * i) - min_v] = true;
            }
            ret++;
        }
    }

    for(long long i = 0; i <= max_v - min_v; i++) {
        if (!is_square[i]) answer++;
    }

    cout << answer;
    return 0;
}
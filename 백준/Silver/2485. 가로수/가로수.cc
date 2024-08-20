#include <iostream>
using namespace std;

int N, answer = 0;
int tree[100001];

int gcd(int x, int y) {
    int r;
    while(y != 0) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) cin >> tree[i];

    int interval = tree[1] - tree[0];
    for(int i=2; i < N; i++) {
        interval = gcd(interval, tree[i] - tree[i-1]);
    }
    
    cout << (tree[N-1] - tree[0]) / interval - N + 1;

    return 0;
}
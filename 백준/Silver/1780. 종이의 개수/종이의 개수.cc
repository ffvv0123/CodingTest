#include <iostream>
using namespace std;

int N;
int cnt[3];
int paper[2200][2200];

bool check (int x, int y, int n) {
    for(int i=x; i < x+n; i++) {
        for(int j=y; j < y+n; j++) {
            if (paper[x][y] != paper[i][j]) return false;
        }
    }
    return true;
}

void solve(int x, int y, int k) {    
    if (check(x, y, k)) {
        cnt[paper[x][y] + 1]++;
        return;
    }

    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            solve(x + i*k/3, y + j*k/3, k/3);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            cin >> paper[i][j];
    
    for(int i=0; i < 3; i++) cnt[i] = 0;

    solve(0, 0, N);
    for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";

    return 0;
}
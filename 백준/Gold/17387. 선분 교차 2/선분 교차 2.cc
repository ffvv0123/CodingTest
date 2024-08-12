#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;


int CCW(pair<long, long> A, pair<long, long> B, pair<long, long> C) {
    long tmp = A.x * B.y + B.x * C.y + C.x * A.y;
	tmp -= B.x * A.y + C.x * B.y + A.x * C.y;

    if (tmp > 0) return 1;
    else if (tmp < 0) return -1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pair<long, long> A, B, C, D;

    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;

    int check1 = CCW(A, B, C) * CCW(A, B, D);
    int check2 = CCW(C, D, A) * CCW(C, D, B);

    if (check1 == 0 && check2 == 0) {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);

        if (A <= D && C <= B) cout << 1;
        else cout << 0;
    }   
    else {
        if (check1 <= 0 && check2 <= 0) cout << 1;
        else cout << 0;
    }
    
    return 0;
}
#include <iostream>
using namespace std;

struct point {
    long x, y;
};

int CCW(point p1, point p2, point p3) {
    long x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y, x3 = p3.x, y3 = p3.y;
    long tmp = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (tmp > 0) return 1;
    else if (tmp < 0) return -1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    point A, B, C, D;

    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;

    int check1 = CCW(A, B, C) * CCW(A, B, D);
    int check2 = CCW(C, D, A) * CCW(C, D, B);

    if (check1 < 0 && check2 < 0) cout << 1;
    else cout << 0;

    return 0;
}
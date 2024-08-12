#include <iostream>
#include <cmath>
using namespace std;

struct point {
    double x;
    double y;
};

int N;
double answer = 0.0;
point P[10001];

double get_area(double x1, double y1, double x2, double y2) {
    double area = P[0].x * y1 + x1 * y2 + x2 * P[0].y;
    area -= P[0].y * x1 + y1 * x2 + y2 * P[0].x;

    return area / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> P[i].x >> P[i].y;
    }

    for(int i=1; i < N; i++) {
        answer += get_area(P[i-1].x, P[i-1].y, P[i].x, P[i].y);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(answer);

    return 0;
}
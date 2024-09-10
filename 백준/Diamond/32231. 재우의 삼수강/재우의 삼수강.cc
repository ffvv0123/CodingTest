#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double get_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    int x1, y1, x2, y2;
    
    cin >> T;
    while (T--) {
        double answer = 0.0;
        cin >> x1 >> y1 >> x2 >> y2;

        int max_y = max(y1, y2);
        int min_y = min(y1, y2);

        answer = 2 * log((get_distance(x1, y1, x2, y2) + get_distance(x1, -y1, x2, y2)) / (2 * sqrt(y1 * y2)));

        cout << fixed << setprecision(7) << answer << '\n';
    }

    return 0;
}


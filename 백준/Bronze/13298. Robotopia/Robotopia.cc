#include <iostream>
using namespace std;

int n, l1, a1, l2, a2, lt, at;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
        int solution_cnt = 0;
        int sol_x = 0, sol_y = 0;

        for(int x = 1; x <= lt / l1; x++) {
            int legs = lt - l1 * x;
            int arms = at - a1 * x;

            if (legs % l2 == 0 && arms % a2 == 0) {
                int y = legs / l2;

                if (y > 0 && y * a2 == arms) {
                    solution_cnt++;
                    sol_x = x;
                    sol_y = y;
                }

                if (solution_cnt > 1) break;
            }
        }

        if (solution_cnt == 1) cout << sol_x << ' ' << sol_y << '\n';
        else cout << "?\n";
    }

    return 0;
}
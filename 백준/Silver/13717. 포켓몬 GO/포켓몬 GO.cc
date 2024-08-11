#include <iostream>
using namespace std;

int N, k, m;
int idv_ans = 0, total = 0;
string p, ans_p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> p;
        cin >> k >> m;

        int tmp = 0;
        while (m - k >= 0) {
            total++;
            m -= k;
            m += 2;
            tmp++;
        }

        if(idv_ans < tmp) {
            ans_p = p;
            idv_ans = tmp;
        }
    }

    cout << total << '\n';
    cout << ans_p;

    return 0;
}
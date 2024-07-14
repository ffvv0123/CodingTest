#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int odd_sum = 0;
    int min_odd = 101;
    int tmp;

    for(int i=0; i < 7; i++) {
        cin >> tmp;
        if (tmp % 2 == 1) {
            odd_sum += tmp;
            if (tmp < min_odd) min_odd = tmp;
        }
    }

    if (odd_sum != 0) {
        cout << odd_sum << "\n";
        cout << min_odd << "\n";
    }
    else cout << -1;
    
    return 0;
}
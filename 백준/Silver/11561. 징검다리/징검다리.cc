/**
 * 1  2  3  4  5  6  7  8  9  10  11  12  13  14
 * 1  3  6  10 15 21 28 36 45 55  66  78  91  105
 * 
 * N(N+1) = 2*10^16 
 * N ~= sqrt(2) * 10^8 -> 10^9
 * 
 */

#include <iostream>
using namespace std;
#define ll unsigned long long 

int T;
ll N;

ll operation(ll num) {
    return num * (num + 1) / 2;
}

int binary_search(ll N) {
    ll low = 0, high = N;

    while(low <= high) {
        ll mid = (low + high) / 2;

        if (operation(mid) > N) {
            high = mid - 1;
        }

        else if (operation(mid) < N){
            low = mid + 1;
        }

        else {
            return mid;
        }
    }

    return high;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;
        cout << binary_search(N) << '\n';
    }

    return 0;
}
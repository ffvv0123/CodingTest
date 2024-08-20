#include <iostream>
using namespace std;

long long t, n;

long long find_prime(long long p) {
    while(1) {
        bool checker = false;
        for(long long i=2; i * i <= p; i++) {
            if (p % i == 0) {
                checker = true;
                break;
            }
        }
        if(checker) p++;
        else return p;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        if (n <= 2) cout << 2 << '\n';
        else cout << find_prime(n) << '\n';
    }

    return 0;
}
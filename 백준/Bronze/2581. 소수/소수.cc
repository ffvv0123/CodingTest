#include <iostream>
#include <cmath>

using namespace std;

int M, N;
int prime_sum = 0, min_prime = -1;

bool is_prime(int p) {
    if (p < 2) return false;

    for(int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;

    for(int i = N; i >= M; i--) {
        if (is_prime(i)) {
            prime_sum += i;
            min_prime = i;
        }
    }

    if (min_prime == -1) cout << -1;
    else {
        cout << prime_sum << '\n';
        cout << min_prime;
    }
    
    return 0;
}
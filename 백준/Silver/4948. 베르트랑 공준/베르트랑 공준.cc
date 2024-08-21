#include <iostream>
#include <cstring>
using namespace std;

int N, answer;
bool is_prime[250000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(is_prime, true, sizeof(is_prime));

    is_prime[0] = false; is_prime[1] = false;
    for(int i=2; i*i <= 250000; i++) {
        if (is_prime[i]) {
            for(int j = i*i; j < 250000; j += i) {
                is_prime[j] = false;
            }
        }
    }

    while(true) {
        answer = 0;

        cin >> N;
        if(N == 0) break;

        for(int i=N+1; i <= 2*N; i++) {
            if(is_prime[i]) answer++;
        }
        cout << answer << '\n';
    }

    return 0;
}
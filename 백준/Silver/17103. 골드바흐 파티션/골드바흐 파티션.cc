#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int T, N;
bool is_prime[1000002];
vector<int> prime;

void set_prime() {
    fill(is_prime, is_prime + 1000002, true);

    for(int i=2; i <= 1000000; i++) {
        if (!is_prime[i]) continue;

        prime.push_back(i);
        for(int j = i*2; j <= 1000000; j += i) {
            is_prime[j] = false;
        }
    }
}

void number_of_partition(int N) {
    int partition = 0;
    
    // 골드바흐 추측이 만족한다고 가정하고 풀이 진행
    for(int p : prime) {
        if (p > N/2) break;
        if (is_prime[N - p]) partition++;
    }

    cout << partition << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set_prime();

    cin >> T;
    while(T--) {
        cin >> N;
        number_of_partition(N);
    }

    return 0;
}
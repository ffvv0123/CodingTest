#include <iostream>
using namespace std;

int N;

int sum_power1(int N) {
    return N * (N+1) / 2;
}

int sum_power2(int N) {
    return sum_power1(N) * sum_power1(N);
}

int sum_power3(int N) {
    return N * N * (N+1) * (N+1) / 4;
}

int main() {
    cin >> N;
    cout << sum_power1(N) << '\n';
    cout << sum_power2(N) << '\n';
    cout << sum_power3(N) << '\n';
    
    return 0;
}
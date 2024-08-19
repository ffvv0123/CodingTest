#include <iostream>
using namespace std;

long long llexp(int base, int exp) {
    long long result = 1;

    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main(){
    string N;
    cin >> N;

    int size = N.length();

    long long ans = 0;
    for (int i = 0; i < size - 1; i++){
        ans += 9 * (i + 1) * llexp(10, i);
    }
    
    long long calc = size * (stoll(N) - llexp(10, size - 1) + 1);
    ans += calc;
    
    cout << ans % 1234567;
    return 0;
}
#include <iostream>
using namespace std;

int gcd(int A, int B) {
    if(A < B) swap(A, B);

    int n;
    while(B != 0) {
        n = A % B;
        A = B;
        B = n;
    }
    return A;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, A, B;
    cin >> T;

    while(T--) {
        cin >> A >> B;
        cout << A * B / gcd(A, B) << '\n';
    }
    

    return 0;
}
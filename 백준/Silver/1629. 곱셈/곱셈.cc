/**
 * A ^ B % C
 * 
 * B가 짝수: A^B = A^(B/2) * A^(B/2)
 * B가 홀수: A^B = A^(B/2) * A^(B/2 + 1)
 * 
 * X = AB
 * X % C = (A % C) * (B % C)
 */

#include <iostream>
using namespace std;

long long A, B, C;

long long multiple(long long x) {
    if (x == 0) return 1;
    if (x == 1) return A % C;

    long long k = multiple(x / 2) % C;

    if (x % 2 == 0) return (k * k) % C;
    else return ((k * k) % C * (A % C)) % C;
}

int main(){

    cin >> A >> B >> C;
    
    cout << multiple(B) % C;

    return 0;
}
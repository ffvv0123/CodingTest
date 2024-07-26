/**
 * A -> A'
 * let a1 = A, a2 ~ ak = -1, ak+1 ~ an = 1
 * -> A * (-1)^m * (1)^n (m % 2 == 0) -> A
 * -> A - m + n -> A'
 * 
 * n - m 은 자유롭게 조절할 수 있음. -> 항상 yes.
 * 다른 조건이 없어서 가능
 */

#include <iostream>
using namespace std;

int T, A, B;

int main() {
    cin >> T;
    cin >> A >> B;

    for(int i=0; i < T; i++)
        cout << "yes\n";

    return 0;
}
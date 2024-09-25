#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string A, B, C = "";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B;

    int len_A = A.length(), len_B = B.length();
    int carry = 0;

    string err = "";
    for (int i = 0; i < abs(len_A - len_B); i++) {
        err += '0';
    }

    if (len_A > len_B) {
        B = err + B;
        len_B = len_A;
    }
    else if (len_A < len_B) {
        A = err + A;
        len_A = len_B;
    }

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    for (int i = 0; i < len_A; i++) {
        if (A[i] - '0' + B[i] - '0' + carry >= 10) {
            C += (A[i] - '0' + B[i] - '0' + carry) % 10 + '0';
            carry = 1;
        }
        else {
            C += (A[i] - '0' + B[i] + carry);
            carry = 0;
        }
    }
    

    reverse(C.begin(), C.end());
    if (carry == 1) C = '1' + C;
    cout << C;

    return 0;
}
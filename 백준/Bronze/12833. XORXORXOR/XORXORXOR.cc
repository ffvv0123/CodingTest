#include <iostream>
using namespace std;

unsigned int A, B, C;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B >> C;

    if (C % 2 == 0) answer = A;
    else answer = A ^ B;

    cout << answer;

    return 0;
}

#include <iostream>
using namespace std;

long long k, a, b, c, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    cin >> a >> b >> c >> d;

    long long left_sum = a*k + b;
    long long right_sum = c*k + d;

    if(left_sum == right_sum) cout << "Yes " << left_sum;
    else cout << "No";

    return 0;
}
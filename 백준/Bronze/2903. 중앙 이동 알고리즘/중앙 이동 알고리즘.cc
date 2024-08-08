#include <iostream>
#include <cmath>

using namespace std;

int N, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    ans = pow((1 + pow(2, N)), 2);

    cout << ans;
    
    return 0;
}
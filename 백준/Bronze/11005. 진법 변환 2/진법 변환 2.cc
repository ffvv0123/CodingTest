#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, B, tmp;
string ans = "";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> B;
    while (N != 0) {
        tmp = N % B;
        if (tmp > 9) {
            tmp = tmp - 10 + 'A';
            ans += tmp;
        }
        else {
            ans += (tmp + '0');
        }
        N /= B;
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
    
    return 0;
}
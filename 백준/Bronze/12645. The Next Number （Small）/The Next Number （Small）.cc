#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        string num;
        cin >> num;

        if (next_permutation(num.begin(), num.end())) {
            cout << "Case #" << t << ": " << num << '\n';
        }
        else {
            int idx = 0;
            while(num[0] == '0') {
                swap(num[0], num[idx++]);
            }

            num = num.substr(0, 1) + "0" + num.substr(1);
            cout << "Case #" << t << ": " << num << '\n';
        }
    }

    return 0;
}
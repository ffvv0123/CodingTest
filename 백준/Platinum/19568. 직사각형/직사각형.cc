#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (i == 15 && j < 15) cout << 1;
            else if (i == 15 && j > 15) cout << 15;
            else if (j == 15 && i < 15) cout << 225;
            else if (j == 15 & i > 15) cout << 3375;
            else cout << 0;
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
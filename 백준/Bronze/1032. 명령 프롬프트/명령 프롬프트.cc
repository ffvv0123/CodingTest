#include <iostream>
using namespace std;

int N;
string input_data, reference;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> reference; N--;

    int length = reference.length();

    while (N--) {
        cin >> input_data;
        for (int i = 0; i < length; i++) {
            if (input_data[i] != reference[i]) {
                reference[i] = '?';
            }
        }
    }

    cout << reference;

    return 0;
}

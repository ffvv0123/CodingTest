#include <iostream>
using namespace std;

string input_data;
int T, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> input_data;
    cin >> T;
    
    while(T--) {
        cin >> a >> b;

        char tmp = input_data[b];
        input_data[b] = input_data[a];
        input_data[a] = tmp;
    }

    cout << input_data;

    return 0;
}
#include <iostream>
#include <list>
using namespace std;

int T, L;
string input_data;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> input_data;
        L = input_data.length();

        list<char> password;
        auto cursor = password.end();

        for(int i=0; i < L; i++) {
            if (input_data[i] == '<') {
                if (cursor == password.begin()) continue;
                cursor--;
            }
            else if (input_data[i] == '>') {
                if (cursor == password.end()) continue;
                cursor++;
            }
            else if (input_data[i] == '-') {
                if (cursor == password.begin()) continue;
                cursor--;
                cursor = password.erase(cursor);
            }
            else {
                password.insert(cursor, input_data[i]);
            }
        }

        for(auto i : password) cout << i;
        cout << '\n';
    }

    return 0;
}